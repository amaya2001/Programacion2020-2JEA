using System;
namespace Agregacion
{
    class Edificio{
        private string direccion;
        private int cantDepartamentos;
        private int depRentados;
    

    public Edificio( string _direccion, int _cantDepartamentos, int _depRentados ){
        direccion = _direccion;
        cantDepartamentos = _cantDepartamentos;
        depRentados = _depRentados;
    }

    public void Muestra(){
        Console.WriteLine( "El edifio tiene: " + direccion + cantDepartamentos + depRentados );
    }
 }
}