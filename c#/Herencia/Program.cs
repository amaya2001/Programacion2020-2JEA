using System;
using Herencia.Futbolistas;

namespace Herencia
{
    class Program
    {
        static void Main(string[] args)
        {
            Delantero fut1 = new Delantero();
            fut1.Nombre = "Carlos";
            fut1.Entrenar();
            
            Arquero ar1 = new Arquero();
            ar1.Nombre = "Julian";
            ar1.TaparGol();
        }
    }
}
