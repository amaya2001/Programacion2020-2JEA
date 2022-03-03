using System;
using Banco.Usuarios;
using Banco.cuentas;

namespace Banco
{
    class Program
    {
        static void Main(string[] args)
        {
            Cliente usuario1 = new Cliente(){
                Nombre = "Miguel",
                Documento = "1014645363",
                Password = 1234,
                Celular = "3166466"
            };

            usuario1.CuentaPrincipal = new cuentas.CuentasAhorros(){
                NumeroCuenta = 4545353535,
                Clave = 1234,
                Tope = 500000 
            };

            usuario1.CuentaPrincipal.IngresarSaldo( 50000 );
            Console.Write( usuario1.CuentaPrincipal.Saldo );
        }
    }
}
