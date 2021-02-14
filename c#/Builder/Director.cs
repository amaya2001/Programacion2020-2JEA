namespace Builder
{
    public class Director
    {
         #region Properties
        private EmpleadoBuilder builder;
        #endregion Properties
        
        
        #region Getters & Setters
        public EmpleadoBuilder Builder
        {
            get { return builder; }
            set { builder = value; }
        }
        #endregion Getters & Setters

        #region Methods
        
        public Empleado ConstruirEmpleado(string nombre, int edad, string userName, string password,
                                   string direccion, string barrio, string ciudad, string complementos)
        {
            Builder.ConstruirDatosBasicos(nombre, edad);
            Builder.ConstruirPlanSalud();
            Builder.ConstruirEmail(userName, password);
            Builder.CrearDireccion(direccion, barrio, ciudad, complementos);
            return Builder.Empleado;
        }

        #endregion Methods

    }
}