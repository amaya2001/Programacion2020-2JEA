using System;
namespace linq.Torneo {
    class Observador: IObservador
    {
        private string nombre;
        private Sujeto sujeto;


        public Observador(string pnombre,Sujeto psujeto){
            nombre = pnombre;
            sujeto = psujeto;
            sujeto.Suscribir(this);
        }

        public void Update(string mensaje){
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("Notificacion {0}, -> {1}", nombre, mensaje);
        }

    }
}