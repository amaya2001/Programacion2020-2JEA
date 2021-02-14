using System;
using System.ComponentModel.DataAnnotations;

namespace TiendaDeCarlos.Models
{
    public class ComprasModel
    {
        [Key]
        public int Id {get; set;}
        public DateTime Fecha {get; set;}
        public int IdCliente {get; set;}
        public int Cantidad {get; set;}
        public string NombreProducto {get; set;}
    }
}