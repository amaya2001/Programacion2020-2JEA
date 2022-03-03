namespace Banco.cuentas{
    public class CuentasAhorros
    {
        #region propierties
        public long NumeroCuenta { get; set; }
        private double saldo;
        private int clave;
        private double tope;

        #endregion propierties

        #region getersYseters
        public double Saldo
        {
            get { return saldo; }
           // set { saldo = value; } -> Para que no se pueda modificar directamente sino mediante un metodo
        }
        public int Clave
        {
            get { return clave; }
            set { clave = value; }
        }
         public double Tope
        {
        
            get { return tope; }
            set { tope = value; }
        }

        #endregion getersYseters

        #region Methods

        public void IngresarSaldo( double dinero ){
            if( dinero > 0 && dinero < Tope ){
                 this.saldo += dinero;
            }

        }

        #endregion
          
    }
}