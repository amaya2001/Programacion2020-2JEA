using BancoFachada.Productos;
namespace BancoFachada.Cliente{
    public class Clientes
    {
        #region propierties
        public string Nombre { get; set; }
        public string Apellidos { get; set; }
        public string documento;
        public string celular;
        public CuentaAhorros MiCuenta { get; set; }

        #endregion propierties

        #region Inicializacion

        public Clientes( CuentaAhorros cuenta )
        {
            MiCuenta = cuenta; // Composicion, si o si, tenga una cuenta de ahorros
        }

        #endregion Inicializacion
    }
}