using System.ComponentModel.DataAnnotations;

namespace Libreria.Models
{
    public class AutorModel{

        [Key]
        public long Id { get; set; }
        public string Nombre { get; set; }
        //public DateTime FechaNacimiento { get; set; }
        public int CantidadLibros { get; set; }
    }
}