namespace Builder.TiposEmpleados
{
    public class Desarrollador : EmpleadoBuilder
    {
        #region Initialize
        public Desarrollador()
        {
            Empleado = new Empleado();
        }
        #endregion Initialize

        #region Methods
        public override void ConstruirDatosBasicos(string nombre, int edad)
        {
            Empleado.Nombre = nombre;
            Empleado.Edad = edad;
            Empleado.Sueldo = 2000000;
        }

        public override void ConstruirEmail(string usuario, string password)
        {
            Email email= new Email();
            email.Usuario = usuario;
            email.Password = password;
            email.Dominio = "@desarrolloEmpresa.com";
            Empleado.Email = email;
        }

        public override void ConstruirPlanSalud()
        {
            PlanSalud plan = new PlanSalud();
            plan.TipoPlan = "Intermedio";
            plan.CantidadCitasGratis = 10;
            Empleado.PlanSalud = plan;
        }

        public override void CrearDireccion(string direcccion, string barrio, string ciudad, string complementos)
        {
            Direccion direccionNueva = new Direccion();
            direccionNueva.DireccionEmpleado = direcccion;
            direccionNueva.Barrio = barrio;
            direccionNueva.Ciudad = ciudad;
            direccionNueva.Complementos = complementos;
            Empleado.Direccion = direccionNueva;
        }
        #endregion Methods
    }
}