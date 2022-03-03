using System;

namespace Excepciones.CustomExceptions
{
    public class LoseForWException : Exception
    {
        public LoseForWException() { }
        public LoseForWException(string Message) : base(String.Format("El equipo {0} ha perdido por W", Message)) { }

        public string NombreEquipo { get; set; }
    }


     public class OpcionNoValida: Exception
    {
        public OpcionNoValida() { }
        public OpcionNoValida(string Message) : base(String.Format("La opcion {0} no existe, selecciona nuevamente", Message)) { }

        public string opcion { get; set; }
    }


     public class NoExisteElemento: Exception
    {
        public NoExisteElemento() { }
        public NoExisteElemento(string Message) : base(String.Format("No existe la posicion {0} en la lista", Message)) { }

        public string elemento { get; set; }
    }
}