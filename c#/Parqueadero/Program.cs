using System;

namespace Parqueadero
{
    class Program
    {
        static void Main(string[] args)
        {
            Parqueadero p1 = new Parqueadero( "Parqueadero de pepe", 50 );
            Carros car1 = new Carros( "Mazda", "Blanco" );
            p1.Mostrar();
            p1.EntraCarro( car1 );
            p1.Mostrar();
            Console.WriteLine("\n=============================================");
            Usuarios Ana = new Usuarios("Juan", "221345", "19" );
            Ana.Mostrar();
        }
    }
}
