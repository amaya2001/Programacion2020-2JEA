using System;
using ejercicio2.Banco.Cuentas;

namespace ejercicio2
{
    class Program
    {
        static void Main(string[] args)
        {
            CuentaAhorros cuenta1 = new CuentaAhorros();
            cuenta1.Referencia = "abc123";
            cuenta1.Saldo = 500000;
            cuenta1.Clave = 1234;
            double saldito = cuenta1.GetSaldo(1234, "aBc123");
            Console.Write( "El saldo es: " + saldito );
        }
    }
}
