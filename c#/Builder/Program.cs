using System;
using Builder.TiposEmpleados;

namespace Builder
{
    class Program
    {
        static void Main(string[] args)
        {
            #region Builder
            Director creadorEmpleados = new Director();
            creadorEmpleados.Builder = new Desarrollador();
            Empleado empleado = creadorEmpleados.ConstruirEmpleado("Jeremias", 20, "JereStar", "password123", "Avenidad Siempre Viva",
                                                    "Barrio2", "Cali", "Bloque 9 Apto 203");
            Console.WriteLine(empleado.Email.Dominio);
            #endregion Builder

        }
    }
}
