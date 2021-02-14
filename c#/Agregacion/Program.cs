using System;

namespace Agregacion
{
    class Program
    {
        static void Main(string[] args)
        {
           Propietario Juan = new Propietario( "Juan" );

           Edificio edif1 = new Edificio( "Av. 1 num 56", 10, 3 );

           Juan.Mostrar();
           Juan.AdicionaPropiedad( edif1 );
           Juan.Mostrar();

           // Propietario Ana = new Propietario( "Juan" );
           //Ana.Mostrar;

        }
    }
}
