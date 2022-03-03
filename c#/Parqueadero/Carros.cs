using System;
namespace Parqueadero{

    class Carros{
        private string nombreAuto;
        private string colorAuto;

        public Carros( string _nombre, string _color ){
            nombreAuto = _nombre;
            colorAuto = _color;
        }

        public void Muestra(){
            Console.Write( " Tiene un auto es de marca: " + nombreAuto +" Y es de color: " + colorAuto );
        }
    }
}