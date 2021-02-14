using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Caching.Memory;
using TiendaDeCarlos.Models;
using TiendaDeCarlos.Services;
using TiendaDeCarlos.ViewModels;

namespace TiendaDeCarlos.Controllers
{
    //https://localhost:5001/Cliente
    [Route("[controller]")]
    public class ClienteController : Controller
    {

        #region Properties
        private readonly TiendaDBContext dBContext;
        private IMemoryCache _cache;
        #endregion Properties

        #region Constructor
        public ClienteController(TiendaDBContext dBContext, IMemoryCache cache)
        {
            this.dBContext = dBContext;
            _cache = cache;
        }
        #endregion Constructor


        [HttpGet("CrearClienteDef")]
        public async Task<IActionResult> CrearClienteDef(string username, string nombre, string apellido, string contrasena, string domicilio)
        {
            try
            {
                ClienteModel cliente = dBContext.clientes.First(a => a.Username == username);
                if( cliente == null )
                {
                    int i = Convert.ToInt16(Request.Form["testSelect"]);
                    ClienteModel Cliente = new ClienteModel()
                    {
                        Username = username,
                        Nombre = nombre,
                        Apellido = apellido,
                        Contrasena = contrasena,
                        Domicilio = domicilio,
                        metodoPago = (MetodoPago)i
                    };
                    dBContext.clientes.Add(Cliente);
                    await dBContext.SaveChangesAsync();
                    return RedirectToAction("HomeCliente",Cliente);
                }
                return View("MalCrear");
                
            }
            catch(Exception e)
            {
                return View(e.Message);
            }
        }

        //https://localhost:5001/Cliente/CrearCliente
        [HttpPost("CrearCliente")]
        public IActionResult CrearCliente()
        {
            return View();
        }


        //https://localhost:5001/Cliente/HomeCliente
        [HttpGet("HomeCliente")]
        public async Task<IActionResult> HomeCliente(ClienteModel cliente)
        {
            ClienteViewModel ClienteView = new ClienteViewModel()
            {
                Id = cliente.Id,
                Username = cliente.Username,
                Nombre = cliente.Nombre,
                Apellido = cliente.Apellido,
                Contrasena = cliente.Contrasena,
                Domicilio = cliente.Contrasena,
                metodoPago = cliente.metodoPago
            };
            cliente.productosCarrito.ForEach(producto => ClienteView.productosCarrito.Add(producto));
            ClienteView.productos = await dBContext.productos.ToListAsync(); 
            return View(ClienteView);
        }

        //https://localhost:5001/Cliente/CarritoCliente
        [HttpPost("CarritoCliente")]
        public async Task<IActionResult> CarritoCliente(int id)
        {
            ClienteModel cliente = await dBContext.clientes.FindAsync(id);
            ClienteViewModel ClienteView = new ClienteViewModel()
            {
                Id = cliente.Id,
                Username = cliente.Username,
                Nombre = cliente.Nombre,
                Apellido = cliente.Apellido,
                Contrasena = cliente.Contrasena,
                Domicilio = cliente.Contrasena,
                metodoPago = cliente.metodoPago
            };

            List<ProductoModel> products = await dBContext.productos.ToListAsync();
            foreach( ProductoModel producto in products)
            {
                int cuantos = 0;
                if( _cache.TryGetValue(producto.Nombre, out cuantos) )
                {
                    ClienteView.productosCarrito.Add(producto);
                    ClienteView.TotalCompra += producto.Precio * cuantos ;
                    ClienteView.productosAPagar.Add(producto.Nombre, cuantos);
                }
            }
            return View(ClienteView);
        }

        [HttpPost("AgregarProductoCanasta")]
        public async Task<IActionResult> AgregarProductoCanasta( int idpro, int IdCliente)
        {
            try
            {
                ClienteModel cliente = await dBContext.clientes.FindAsync(IdCliente);
                ProductoModel canasta = await dBContext.productos.FindAsync(idpro);
                AgregarCache(canasta, cliente);
                return RedirectToAction("HomeCliente",cliente);
            }
            catch( Exception e)
            {
                return View(e.Message);
            }
        }

        [OutputCache(Duration  = 600)]
        private void AgregarCache(ProductoModel producto, ClienteModel cliente)
        {
            int cuantos = 0;
            if( _cache.TryGetValue(producto.Nombre, out cuantos) )      
            {
                cuantos++;
                _cache.Set(producto.Nombre, cuantos);
            }
            else
            {
                _cache.Set(producto.Nombre, 1);
            }
            
        }

        [HttpPost("CasiHome")]
        public async Task<IActionResult> CasiHome(int IdCliente)
        {
            try
            {
                ClienteModel cliente = await dBContext.clientes.FindAsync(IdCliente);
                return RedirectToAction("HomeCliente", cliente);
            }
            catch(Exception e)
            {
                return View(e.Message);
            }
        }

        [HttpPost("PagarProductos")]
        public async Task<IActionResult> PagarProductos( int IdClientes )
        {
            try
            {
                ClienteModel cliente = await dBContext.clientes.FindAsync(IdClientes);
                DateTime fechaActual = DateTime.Now;
                List<ProductoModel> products = await dBContext.productos.ToListAsync();
                foreach( ProductoModel producto in products)
                {
                    int cuantos = 0;
                    ComprasModel compras = new ComprasModel();
                    if( _cache.TryGetValue(producto.Nombre, out cuantos) )
                    {
                        compras.NombreProducto = producto.Nombre;
                        compras.Fecha = fechaActual;
                        compras.IdCliente = IdClientes;
                        compras.Cantidad = cuantos;
                    }
                    producto.Cantidad -= cuantos;
                    dBContext.Entry(producto).State = EntityState.Modified;
                    dBContext.compras.Add(compras);
                    await dBContext.SaveChangesAsync();
                    _cache.Remove(producto.Nombre);
                }
                return RedirectToAction("HomeCliente","Cliente",cliente);
            }
            catch( Exception e)
            {
                return View(e.Message);
            }
        }


        //https://localhost:5001/Cliente/Historial
        [HttpPost("Historial")]
        public async Task<IActionResult> Historial( int idCliente )
        {
            List<ComprasModel> Compras = await dBContext.compras.ToListAsync();
            List<ComprasModel> CompraCliente = new List<ComprasModel>();
            foreach( ComprasModel c in Compras )
            {
                if( c.IdCliente == idCliente )
                {
                    CompraCliente.Add(c);
                }
            }
            return View(CompraCliente);
        }

        public async Task<IActionResult> CerrarSesion()
        {
            List<ProductoModel> products = await dBContext.productos.ToListAsync();
            foreach( ProductoModel producto in products)
            {
                int cuantos = 0;
                if( _cache.TryGetValue(producto.Nombre, out cuantos) )
                    _cache.Remove(producto.Nombre);
             }
            return RedirectToAction("Login","CarlosStore");
        }
    }
}