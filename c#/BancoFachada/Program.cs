using System;
using BancoFachada.Tramites;
namespace BancoFachada
{
    class Program
    {
        static void Main(string[] args)
        {
            FachadaAhorros FachadaBanco = new FachadaAhorros();
            FachadaBanco.SaludarCliente();
        }
    }
}
