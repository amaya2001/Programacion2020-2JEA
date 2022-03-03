using System.ComponentModel.DataAnnotations;
using Microsoft.AspNetCore.Http;

namespace TiendaDeCarlos.Models
{
    public class ProductoModel
    {
        #region Properties
        [Key]
        public int Id {get; set;}
        public string Nombre {get; set;}
        public int Cantidad {get; set;}
        public int IdVendedor {get; set;}
        public double Precio {get; set;}
        public string Imagen {get; set;}
        #endregion Properties
    }
}