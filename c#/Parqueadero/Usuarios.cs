using System;
namespace Parqueadero{
    public class Usuarios{
        private string nombreUsario;
        private string celular;
        private string edad;
        private Carros car1 = null;
        public Usuarios( string _nombre, string _celular, string _edad ){
            nombreUsario = _nombre;
            celular = _celular;
            edad = _edad;
            car1 = new Carros( "Audi", "Gris" );
        }

        public void Mostrar(){
            if( car1 != null){
                Console.Write( " El usuario " + nombreUsario );
                car1.Muestra();
            }

        }

    }
}