namespace Ejemplo2Repaso.Banco.Cuentas 
{
    public class CuentasAhorros
    {
        #region propierties

        private int clave;

        private double saldo;

        private string referencia;

        #endregion propierties

        #region getersYseters

        public int Clave
        {
            set 
            { 
                if( value != clave ){
                    clave = value;
                } 
            }
        }

        private double Saldo
        {
            get { return saldo; }
            set { saldo = value; }
        }

        public string Referencia
        {
            get 
            { 
                return referencia.ToUpper(); 
            }
            set { referencia = value; }
        }

        #endregion getersYseters
        
        #region Methods

        public double getSaldo( int claveAcceso, string referenciaUsuario )
        {
            double response = 0;
            if( this.clave == claveAcceso && Referencia.ToUpper() == referenciaUsuario ){
                response = Saldo;

                return response;
            }

        }

        #endregion Methods
        
    }
}