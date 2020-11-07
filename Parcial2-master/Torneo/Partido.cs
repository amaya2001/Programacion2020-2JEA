using System;
using System.Collections.Generic;
using System.Linq;
using Excepciones.CustomExceptions;

namespace linq.Torneo
{
    public class Partido
    {
        #region Properties  
        public Equipo EquipoLocal { get; set; }
        public Equipo EquipoVisitante { get; set; }

        #endregion Properties

        #region Initialize
        public Partido(Seleccion EquipoLocal, Seleccion EquipoVisitante)
        {
            this.EquipoLocal = new Equipo(EquipoLocal);
            this.EquipoVisitante = new Equipo(EquipoVisitante);
        }
        #endregion Initialize
        #region Methods
        private void CalcularExpulsiones()
        {
            Random random = new Random();
            List<Jugador> JugadoresLocales = EquipoLocal.Seleccion.Jugadores;
            List<Jugador> JugadoresVisitantes = EquipoVisitante.Seleccion.Jugadores;
            int position = random.Next(JugadoresLocales.Count);
            int totalAmarillasJugadorLocal = JugadoresLocales[position].TarjetasAmarillas;
            //Console.WriteLine("totalAmarillasJugadorLocal " + totalAmarillasJugadorLocal +" Jugador "+JugadoresLocales[position].Nombre);
            if (totalAmarillasJugadorLocal < 2)
            {
                JugadoresLocales[position].TarjetasAmarillas = totalAmarillasJugadorLocal + 1;
            }
            else
            {                
                EquipoLocal.ExpulsarJugador(JugadoresLocales[position].Nombre);
            }
            position = random.Next(JugadoresVisitantes.Count);
            int totalAmarillasJugadorVisitante = JugadoresVisitantes[position].TarjetasAmarillas;
            if (totalAmarillasJugadorVisitante < 2)
            {
                JugadoresVisitantes[position].TarjetasAmarillas = totalAmarillasJugadorVisitante + 1;
            }
            else
            {
                EquipoVisitante.ExpulsarJugador(JugadoresVisitantes[position].Nombre);
            }
        }


        private void CalcularResultado()
        {
            Random random = new Random();
            EquipoLocal.Goles = random.Next(0, 6);
            EquipoVisitante.Goles = random.Next(0, 6);
        }

        public string Resultado()
        {
            string resultado = "0 - 0";
            Random random = new Random();
            try
            {
                int iteraciones = random.Next(2, 10);
                for (int i = 0; i < iteraciones; i++)
                {
                    CalcularExpulsiones();
                }
                CalcularResultado();
                resultado = EquipoLocal.Goles.ToString() + " - " + EquipoVisitante.Goles.ToString();
            }
            catch (LoseForWException ex)
            {
                Console.WriteLine(ex.Message);
                EquipoLocal.Goles -= EquipoLocal.Goles;
                EquipoVisitante.Goles -= EquipoVisitante.Goles;
                if (ex.NombreEquipo == EquipoLocal.Seleccion.Nombre)
                {
                    EquipoVisitante.Goles += 3;
                    resultado = "0 - 3";
                }
                else
                {
                    EquipoLocal.Goles += 3;
                    resultado = "3 - 0";
                }
            }

            return resultado;
        }
        #endregion Methods

    }
}