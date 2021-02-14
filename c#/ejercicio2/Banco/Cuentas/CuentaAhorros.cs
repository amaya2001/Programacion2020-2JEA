namespace ejercicio2.Banco.Cuentas
{
    public class CuentaAhorros
    {
        #region propierties

        private int clave;

        private double saldo;

        private string referencia;

        #endregion propierties

        #region geters & seters

        public int Clave
        {
            set 
            { 
                if( value != clave ) // por si se quiere modificar clave
                {
                     clave = value;
                } 
            }
        }

        public double Saldo
        {
             set { saldo = value; }
        }

         public string Referencia
        {
            get { return referencia; }
            set 
            { 
                referencia = value.ToUpper(); 
            }
        }

        #endregion geters & seters

        #region methods

        public double GetSaldo( int claveAcceso, string referenciaUsuario )
        {
            double response = 0;
            if( this.clave == claveAcceso && referenciaUsuario.ToUpper() == Referencia )
            {
                response = this.saldo;
            }
            return response;
        }
        #endregion methods
    }

}