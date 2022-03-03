using Banco.cuentas;
namespace Banco.Usuarios{
    public class Cliente
    {
        #region propierties
        public string Nombre { get; set; }
        private string documento;
        private int password;
        private string celular;
        private CuentasAhorros cuentaPrincipal;

        #endregion propierties

        #region getersYseters
        public string Documento
        {
            get { return documento; }
            set { documento = value; }
        }
        public int Password
        {
            get { return password; }
            set { password = value; }
        }
        public string Celular
        {
            //get { return celular; } -> Internamente se va a hacer un metodo para enviar el mensaje pero nadie necesita conocerlo
            set { celular = value; }
        }
        public CuentasAhorros CuentaPrincipal
        {
            get { return cuentaPrincipal; } 
            set 
            {
                if( cuentaPrincipal == null ){
                    cuentaPrincipal = value;
                } 
            }
        }
        
        #endregion getersYseters
        
    }
}