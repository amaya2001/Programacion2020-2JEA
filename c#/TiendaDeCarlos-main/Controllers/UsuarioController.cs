using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using TiendaDeCarlos.Models;
using TiendaDeCarlos.Services;

namespace TiendaDeCarlos.Controllers
{
    //https://localhost:5001/Usuario
    [Route("[controller]")]
    public class UsuarioController : Controller
    {

        #region Properties
        private readonly TiendaDBContext dBContext;
        #endregion Properties

        #region Constructor
        public UsuarioController(TiendaDBContext dBContext)
        {
            this.dBContext = dBContext;
        }
        #endregion Constructor

        public enum MetodoPago
        {
            TarjetaCredito = 0,
            PayPal = 1,
            CuentaAhorros = 2
        }

        public IActionResult MalLogin()
        {
            return View();
        }

        //https://localhost:5001/Usuario/Loginn
        [HttpPost("Loginn")]
        public async Task<IActionResult> Loginn( UsuarioWebModel usuario )
        {
            UsuarioWebModel cam = new UsuarioWebModel();
            try
            { 
                List<CampesinoModel> Campesinos = await dBContext.campesinos.ToListAsync();
                cam = Campesinos.First(a => a.Username == usuario.Username && a.Contrasena == usuario.Contrasena);
                return RedirectToAction("HomeCampesino", "Campesino", cam); 
            }
            catch( Exception e)
            {   
                try
                {
                    List<ClienteModel> Clientes = await dBContext.clientes.ToListAsync();
                    cam = Clientes.First(a => a.Username == usuario.Username && a.Contrasena == usuario.Contrasena);
                    return RedirectToAction("HomeCliente", "Cliente", cam);
                }
                catch(InvalidOperationException)
                {
                    return RedirectToAction("MalLogin");
                }
            }
        }

        //https://localhost:5001/Usuario/CrearUsuario
        [HttpGet("CrearUsuario")]
        public IActionResult CrearUsuario()
        {
            return View();
        }

        //https://localhost:5001/Usuario/NoPassword
        [HttpGet("NoPassword")]
        public IActionResult NoPassword()
        {
            return View();
        }

        [HttpPost("Recuperar")]
        public async Task<IActionResult> Recuperar( UsuarioWebModel usuario )
        {
            UsuarioWebModel cam = new UsuarioWebModel();
            try
            { 
                List<CampesinoModel> Campesinos = await dBContext.campesinos.ToListAsync();
                cam = Campesinos.First(a => a.Username == usuario.Username);
                cam.Contrasena = usuario.Contrasena;
                await dBContext.SaveChangesAsync();
                return RedirectToAction("Login","CarlosStore"); 
            }
            catch( Exception e)
            {   
                try
                {
                    List<ClienteModel> Clientes = await dBContext.clientes.ToListAsync();
                    cam = Clientes.First(a => a.Username == usuario.Username);
                    cam.Contrasena = usuario.Contrasena;
                    await dBContext.SaveChangesAsync();
                    return RedirectToAction("Login","CarlosStore"); 
                }
                catch(InvalidOperationException)
                {
                    return RedirectToAction("NoEncontrado");
                }
            }
        }

        //https://localhost:5001/Usuario/NoEncontrado
        [HttpGet("NoEncontrado")]
        public IActionResult NoEncontrado()
        {
            return View();
        }

        
    }
}