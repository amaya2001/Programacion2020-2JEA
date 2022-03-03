namespace ControlPanel.Domain
{
    public class Semilla
    {

        public string Tipo { get; set; }
        public int CantidadAgua { get; set; }
        public int CantidadSombra { get; set; }
        public string Id { get; set; }

        public Semilla()
        {

        }

        public string toString()
        {
            return "Id: " + this.Id + ", Tipo: " + this.Tipo + ", CantidadAgua: " + this.CantidadAgua;
        }

    }
}