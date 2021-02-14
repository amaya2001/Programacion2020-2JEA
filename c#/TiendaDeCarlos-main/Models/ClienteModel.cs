using System;
using System.IO;
using TiendaDeCarlos.Models;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace TiendaDeCarlos.Models
{
    public class ClienteModel : UsuarioWebModel
    {
        #region Properties
        public MetodoPago metodoPago;
        public List<ProductoModel> productosCarrito = new List<ProductoModel>();
        #endregion Properties

        #region Methods
        #endregion Methods

    }
}

    public enum MetodoPago
        {
            [Display(Name = "TarjetaCredito")]
            TarjetaCredito = 0,
            [Display(Name = "PayPal")]
            PayPal = 1,
            [Display(Name = "CuentaAhorros")]
            CuentaAhorros = 2
        }