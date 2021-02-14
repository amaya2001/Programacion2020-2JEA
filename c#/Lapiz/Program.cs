using System;

namespace Ej1
{
    class Program
    {
        static void Main(string[] args)
        {
            Lapiz lapiz1 = new Lapiz()
            {
                LongitudCuerpo = 10,
                LongitudPunta = 10

            };

            Console.WriteLine( "Digite el numero de vueltas: " );
            int Vueltas = Convert.ToInt32(Console.ReadLine());
            lapiz1.SacarPunta( Vueltas );
            ImprimirResultados( lapiz1 );
            void ImprimirResultados( Lapiz lapiz){
                Console.WriteLine( "Punta: "+lapiz.LongitudPunta );
                Console.WriteLine( "Cuerpo: "+lapiz.LongitudCuerpo );
            }
        }
    }
    
}