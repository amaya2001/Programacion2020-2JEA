using System;
namespace Agregacion
{
    class Propietario{
        private string nombre;
        private Edificio propiedad = null;
    

    public Propietario( string _nombre ){
        nombre = _nombre;
        // Propiedad = new Edificio( "Av 2-4", 10, 5 ); -> Composicion
    }

    public void Mostrar(){
        if( propiedad != null){
            Console.WriteLine( "El propietario es: " + nombre );
            propiedad.Muestra();
        }else{
            Console.WriteLine(nombre + " No tienes edificios" );
        }
    }

    public void AdicionaPropiedad( Edificio _edificio ){
        if( _edificio != null){
            propiedad = _edificio;
        }
    }
 }
}