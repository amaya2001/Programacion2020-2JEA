using System;
namespace Herencia.Futbolistas{
    public class Arquero : Futbolista{
    
    #region Methods
    public void TaparGol(){
        Console.Write( "El arquro " + Nombre + " tapo un golll!" );
    }

    #endregion Methods
    }
}