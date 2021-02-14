using System;
using System.IO;
using TiendaDeCarlos.Models;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace TiendaDeCarlos.Models
{
    public class CampesinoModel : UsuarioWebModel
    {
        #region Properties
        public List<ProductoModel> ProductoVendedor = new List<ProductoModel>();
        #endregion Properties

        #region Methods
        
        #endregion Methods

    }
}