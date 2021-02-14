
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Microsoft.AspNetCore.Http;

namespace TiendaDeCarlos.ViewModels
{
    public class ProductoViewModel
    {
        #region Properties
        [Key]
        public int Id {get; set;}
        public string Nombre {get; set;}
        public int Cantidad {get; set;}
        public int IdVendedor {get; set;}
        public double Precio {get; set;}

        [NotMapped]
        [DisplayName("Upload File")]
        public IFormFile ImagenName {get; set;}
        #endregion Properties
    }
}