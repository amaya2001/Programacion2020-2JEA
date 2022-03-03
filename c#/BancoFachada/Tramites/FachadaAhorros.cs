using System;
using BancoFachada.Cliente;
using BancoFachada.Productos;


namespace BancoFachada.Tramites{
    public class FachadaAhorros{
        #region Propierties
        public string NombreCliente { get; set; }
        public string ApellidoCliente { get; set; }
        public string DocumentoCliente { get; set; }   
        public string CelularCliente { get; set; }
        public string OpcionCliente { get; set; }
        public string SaldoCliente { get; set; }
        public string ClaveCliente { get; set; }

        private double topeCuentas;

        #endregion Propierties

        #region GetersYseters
        public double TopeCuentas
        {
           // get { return topeCuentas; }
            set { topeCuentas = value; }
        }

        #endregion GetersYseters

        #region Methods
        public void SaludarCliente(){
            Console.Write("Bienvenido, Como te llamas: ");
            NombreCliente = Console.ReadLine();
            Console.Write("Que tramite desea hacer señor " + NombreCliente + "?\n" );
            Menu();
        }

        public void Menu(){
        Console.Write("Los tramites del banco son: \n 1)Crear Cuenta ahorros ");   
        OpcionCliente = Console.ReadLine();
        if( OpcionCliente == "1" ){
            crearCuentaAhorros();
        }else{
            Console.Write( "Esta opcion no existe" );
        }
        }

        public void crearCuentaAhorros(){
           if( pedirDatosCliente()){
               if( pedirDatosCuenta()){
                   var random = new Random();
                   long numeroCuenta = (long)random.NextDouble(); 
                   CuentaAhorros cuentaCliente = new CuentaAhorros(){
                       Saldo = Convert.ToDouble( SaldoCliente ),
                       Clave = Convert.ToInt32( ClaveCliente ),
                       NumeroCuenta = numeroCuenta,
                       Tope = topeCuentas

                   };

                   Clientes cliente = new Clientes( cuentaCliente );


               }
           }
        }

        private bool pedirDatosCliente(){
            bool respuesta = false;
            Console.Write( "\nA continuacion se le pediran unos datos para la creacion de su cuenta" );
            Console.Write( "Cual es su appelido: " );
            ApellidoCliente = Console.ReadLine();
            Console.Write( "Cual es su documento: " );
            DocumentoCliente = Console.ReadLine();
            Console.Write( "Cual es su celular: " );
            CelularCliente = Console.ReadLine();
            respuesta = validateCliente();

            return respuesta;
        }

        private bool validateCliente(){

            long longnum = 0;
            if( NombreCliente == "" || ApellidoCliente == "" || DocumentoCliente == "" || CelularCliente == "" ){
                return false;
            }

            else if( !long.TryParse(DocumentoCliente, out longnum ) || !long.TryParse( CelularCliente, out longnum ) ){
                return false;
            }

            else if( CelularCliente.Length != 10 ){
                return false;
            }

            return true;
        }

         private bool pedirDatosCuenta(){
            bool respuesta = false;
            Console.Write( "\nA continuacion se le pediran unos datos adicionales" );
            Console.Write( "Con cuanto dinero empezara la cuenta: " );
            SaldoCliente = Console.ReadLine();
            Console.Write( "Cual es su Clave: " );
            ClaveCliente = Console.ReadLine();
            respuesta = validateCuenta();

            return respuesta;
        }

         private bool validateCuenta(){

            long saldo = 0;

            if( !long.TryParse( SaldoCliente, out saldo ) ){
                return false;
            }

            else if( saldo < 0 ){
                return false;
            }

            else if( ClaveCliente.Length != 4){
                return false;
            }

            return true;
        }


        #endregion Methods

        #region Inicializacion

        public FachadaAhorros(){
            topeCuentas = 500000;
        }

        #endregion inicializacion
    }
}