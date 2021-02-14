namespace Builder.TiposEmpleados
{
    public class AuxiliarContable : EmpleadoBuilder
    {
        #region Initialize
        public AuxiliarContable()
        {
            Empleado = new Empleado();
        }
        #endregion Initialize
        #region Methods
        public override void ConstruirDatosBasicos(string nombre, int edad)
        {
            Empleado.Nombre = nombre;
            Empleado.Edad = edad;
            Empleado.Sueldo =1500000;
        }

        public override void ConstruirEmail(string usuario, string password)
        {
            Email email= new Email();
            email.Usuario = usuario;
            email.Password = password;
            email.Dominio = "@contableEmpresa.com";
            Empleado.Email = email;
        }

        public override void ConstruirPlanSalud()
        {
            PlanSalud plan = new PlanSalud();
            plan.TipoPlan = "Básico";
            plan.CantidadCitasGratis = 5;
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