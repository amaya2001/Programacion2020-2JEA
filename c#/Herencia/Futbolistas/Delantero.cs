using System;
namespace Herencia.Futbolistas{
    public class Delantero : Futbolista{
    
    #region Methods
    public void MeterGoles(){
        Console.Write( "El Jugador " + Nombre + " Metio un golll!" );
    }

    #endregion Methods
    }
}