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
    //https://localhost:5001/CarlosStore
    [Route("[controller]")]
    public class CarlosStoreController : Controller
    {
        #region Properties
        private readonly TiendaDBContext dBContext;
        #endregion Properties

        
        #region Constructor
        public CarlosStoreController(TiendaDBContext dBContext)
        {
            this.dBContext = dBContext;
        }
        #endregion Constructor

        //https://localhost:5001/CarlosStore/Login
        [HttpGet("Login")]
        public IActionResult Login()
        {
            return View();
        }
    }
}