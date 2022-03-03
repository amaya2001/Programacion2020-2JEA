using System;
using System.IO;
using TiendaDeCarlos.Models;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace TiendaDeCarlos.ViewModels
{
    public class ClienteViewModel : ClienteModel
    {
        #region Properties
        public List<ProductoModel> productos = new List<ProductoModel>();
        public Dictionary<string, int> productosAPagar = new Dictionary<string, int>();
        public double TotalCompra;
        #endregion Properties

        #region Contructor
        public ClienteViewModel()
        {
            TotalCompra = 0;
        }
        #endregion Contructor

    }
}