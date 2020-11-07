using System;
using System.Collections.Generic;
using System.IO;
using Newtonsoft.Json;
using System.Linq;
using Excepciones.CustomExceptions;
using System.Threading;
namespace linq.Torneo
{
    class Sujeto
    {

        private List<IObservador> observadores = new List<IObservador>();
        private string mensaje;

        public void Suscribir(IObservador observador)
        {
             observadores.Add(observador);
        }

        public void Remover(IObservador observador)
        {
            observadores.Remove(observador);
        }

        private void Notificar()
        {
            foreach (var observer in observadores)
            {
                Thread.Sleep(500);
                observer.Update(mensaje);
            }
        }

        public void ActualizarInfoSeleccion(List<Seleccion> Selecciones, int elemento, int puntos, int goles)
        {
            Selecciones.ElementAt(elemento).GolesTotales = goles;
            Selecciones.ElementAt(elemento).PuntosTotales = puntos;
            string list = JsonConvert.SerializeObject(Selecciones);
            File.WriteAllText("./selecciones.json", list);
            mensaje = "Seleccion " + Selecciones.ElementAt(elemento).Nombre + " actualizada, Goles Totales: " + goles + ", Puntos Totales: " + puntos;
            Notificar();
        }

    }
}