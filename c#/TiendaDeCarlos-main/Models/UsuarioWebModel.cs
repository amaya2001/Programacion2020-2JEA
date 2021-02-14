using System.ComponentModel.DataAnnotations;

namespace TiendaDeCarlos.Models
{
    public class UsuarioWebModel : IUsuarioModel
    {
        #region Properties
        [Key]
        public int Id {get; set;} 
        public string Username {get; set;}

        [Required(ErrorMessage = "Ingrese su nombre")]  
        [Display(Name = "Nombre")]
        [StringLength(100)]    
        public string Nombre {get; set;}
        public string Apellido {get; set;}
        public string Contrasena {get; set;}
        public string Domicilio {get; set;}
        #endregion Properties

        #region Methods
        #endregion Methods
    }
}
