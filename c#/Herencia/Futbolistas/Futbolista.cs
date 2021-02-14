using System;
namespace Herencia.Futbolistas{

    #region Propierties
    public class Futbolista{
    public string Nombre { get; set; }
    public double Estatura { get; set; }
    public bool EsZurdo { get; set; }

    #endregion Propierties

    #region Methods
    public void EntrarAlEstadio(){
        Console.Write( "El Jugador " + Nombre + " Esta entando al estadio" );
    }

    public void Entrenar(){
        Console.Write( "El jugador " + Nombre + " Esta entrenando" );
    }

    #endregion Methods
    }
}