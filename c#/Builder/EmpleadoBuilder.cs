namespace Builder
{
    public abstract class EmpleadoBuilder
    {
         #region Properties
        private Empleado empleado;
        #endregion Properties

        #region Initialize
        #endregion Initialize

        #region Getters & Setters
        public Empleado Empleado
        {
            get { return empleado; }
            set { empleado = value; }
        }
        #endregion Getters & Setters

        #region Methods
        public abstract void ConstruirDatosBasicos(string nombre, int edad);
        public abstract void ConstruirPlanSalud();
        public abstract void ConstruirEmail(string usuario, string password);
        public abstract void CrearDireccion(string direcccion, string barrio, string ciudad, string complementos);

        #endregion Methods
    }
}
