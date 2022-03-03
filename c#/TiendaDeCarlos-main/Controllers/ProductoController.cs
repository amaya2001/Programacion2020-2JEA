using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using TiendaDeCarlos.Models;
using TiendaDeCarlos.Services;
using TiendaDeCarlos.ViewModels;
using Microsoft.Extensions.Caching.Memory;

namespace TiendaDeCarlos.Controllers
{
    //https://localhost:5001/Usuario
    [Route("[controller]")]
    public class ProductoController : Controller
    {

        #region Properties
        private readonly TiendaDBContext dBContext;
        private readonly IWebHostEnvironment hostEnvironment;  


        #endregion Properties

        #region Constructor
        public ProductoController(TiendaDBContext dBContext, IWebHostEnvironment hostEnvironment)
        {
            this.dBContext = dBContext;
            this.hostEnvironment = hostEnvironment;
        }
        #endregion Constructor

        [HttpPost("AgregarProducto")]
        public async Task<IActionResult> AgregarProducto(ProductoViewModel productoV)
        {
            try
            {
                ProductoModel productos = dBContext.productos.First(a=> a.Nombre == productoV.Nombre);
                return RedirectToAction("NoProducto", "Campesino");
              
                
            }
            catch(Exception e)
            {
                    string uniqueFileName = UploadedFile(productoV);  
                    int i = Convert.ToInt16(Request.Form["testSelect"]);
                    ProductoModel producto = new ProductoModel()
                    {
                        Nombre = productoV.Nombre,
                        Cantidad = productoV.Cantidad,
                        IdVendedor = Convert.ToInt16(TempData["Id"]),
                        Precio = productoV.Precio,
                        Imagen = uniqueFileName
                    };
                    producto.Cantidad = i;
                    dBContext.productos.Add(producto);
                    await dBContext.SaveChangesAsync();
                    return RedirectToAction("AgregoProductoCampesino","Campesino", producto);
            }
        }
        private string UploadedFile(ProductoViewModel pro)  
        {  
            string uniqueFileName = null;  
  
            if (pro.ImagenName != null)  
            {  
                string uploadsFolder = Path.Combine(hostEnvironment.WebRootPath, "Pictures");  
                uniqueFileName = Guid.NewGuid().ToString() + "_" + pro.ImagenName.FileName;  
                string filePath = Path.Combine(uploadsFolder, uniqueFileName);  
                using (var fileStream = new FileStream(filePath, FileMode.Create))  
                {  
                    pro.ImagenName.CopyTo(fileStream);  
                }  
            }  
            return uniqueFileName;  
        } 


        [HttpPost("EditarProducto")]
        public async Task<IActionResult> EditarProducto( ProductoModel producto )
        {
            try
            {
                int i = Convert.ToInt16((Request.Form["edit"]));
                producto.Cantidad = i;
                dBContext.Entry(producto).State = EntityState.Modified;
                CampesinoModel cam = await dBContext.campesinos.FindAsync(producto.IdVendedor);
                await dBContext.SaveChangesAsync();
                return RedirectToAction("HomeCampesino","Campesino", cam);
            }
            catch(Exception e)
            {
                return View(e.Message);
            }
        }

        //https://localhost:5001/Producto/CasiEditarProducto
        [HttpPost("CasiEditarProducto")]
        public async Task<IActionResult> CasiEditarProducto( int IdPro, int idCam )
        {
            try
            {
                ProductoModel producto = await dBContext.productos.FirstAsync( a => a.Id == IdPro) ;
                return View( producto );
            }   
            catch( Exception e)
            {
                return View(e.Message);
            }
        }

        [HttpPost("EliminarProducto")]
        public async Task<IActionResult> EliminarProducto( int IdPro, int idCam )
        {
            try
            {
                List<CampesinoModel> Campesinos = await dBContext.campesinos.ToListAsync();
                CampesinoModel cam = new CampesinoModel();
                cam = Campesinos.First(a => a.Id == idCam);
                ProductoModel producto = await dBContext.productos.FindAsync(IdPro);
                dBContext.productos.Remove(producto);
                await dBContext.SaveChangesAsync();
                
                return RedirectToAction("HomeCampesino","Campesino",cam);
            }
            catch( Exception e)
            {
                return View(e.Message);
            }
        }
    }
}