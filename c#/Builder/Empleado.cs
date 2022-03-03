namespace Builder
{
    public class Empleado
    {
         #region Properties
        private string nombre;
        private int edad;
        private double sueldo;
        private PlanSalud planSalud;
        private Direccion direccion;
        private Email email;
        #endregion Properties

        #region Initialize
        #endregion Initialize

        #region Getters & Setters
        public string Nombre
        {
            get { return nombre; }
            set { nombre = value; }
        }
        public double Sueldo
        {
            get { return sueldo; }
            set { sueldo = value; }
        }
        public int Edad
        {
            get { return edad; }
            set { edad = value; }
        }
        public PlanSalud PlanSalud
        {
            get { return planSalud; }
            set { planSalud = value; }
        }
        public Direccion Direccion
        {
            get { return direccion; }
            set { direccion = value; }
        }
        public Email Email
        {
            get { return email; }
            set { email = value; }
        }
        #endregion Getters & Setters

        #region Methods
        #endregion Methods
    }
}