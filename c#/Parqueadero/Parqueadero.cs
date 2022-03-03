using System;
namespace Parqueadero{
    class Parqueadero{
        private string nombreParqueadero;
        private int capacidadParqueadero;
        private Carros carro1 = null;
        public Parqueadero( string _nombre, int _capacidad ){
            nombreParqueadero = _nombre;
            capacidadParqueadero = _capacidad;
        }
        public void EntraCarro( Carros car ){
            if( car != null){
                carro1 = car;
            }
        } 

        public void Mostrar(){
            if( carro1 != null ){
                Console.WriteLine( "El parqueadero se llama: " + nombreParqueadero + ", tiene capacidad " + capacidadParqueadero );
                carro1.Muestra();    
            }else{
                Console.WriteLine( "El parqueadero " + nombreParqueadero + " No tiene carros" );
            }
        }
    }
}