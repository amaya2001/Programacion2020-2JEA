namespace BancoFachada.Productos{
    public class CuentaAhorros
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
            set { saldo = value; } 
        }
        public int Clave
        {
            get { return clave; }
            set { clave = value; }
        }

        public double Tope
        {
            get { return saldo; }
            set { saldo = value; } 
        }
        #endregion getersYseters
    }
}