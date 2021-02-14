namespace ControlPanel.Domain
{
    public class Usuario
    {

        public string Nombre { get; set; }
        public int Clave { get; set; }
        public bool Administrador { get; set; }

        public Usuario()
        {

        }

        public string toString()
        {
            return "Nombre: " + this.Nombre + ", Clave: " + this.Clave + ", Admin: " + this.Administrador;
        }

    }
}