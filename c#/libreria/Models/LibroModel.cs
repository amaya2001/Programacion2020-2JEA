using System.ComponentModel.DataAnnotations;

namespace Libreria.Models
{
    public class LibroModel{

        [Key]
        public long Id { get; set; }
        public string Nombre { get; set; }
        public int CantidadPaginas { get; set; }
        public string Genero { get; set; }
        public long IdAutor { get; set; }
    }
}