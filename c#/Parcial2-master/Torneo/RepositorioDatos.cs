using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using Newtonsoft.Json;


namespace linq.Torneo
{
    public class RepositorioDatos
    {
        #region Properties  
        public List<Seleccion> Selecciones { get; set; }

        #endregion Properties

        #region Initialize
        public RepositorioDatos()
        {
            Selecciones = CrearSelecciones();
        }
        #endregion Initialize


        #region Methods
        private List<Seleccion> CrearSelecciones()
        {
            List<Seleccion> selecciones = new List<Seleccion>();
            string path = "./selecciones.json";
            using (StreamReader jsonStream = File.OpenText(path))
            {
                var json = jsonStream.ReadToEnd();
                dynamic seleccion = JsonConvert.DeserializeObject(json);
                foreach (var item in seleccion)
                {
                    Seleccion objSeleccion = new Seleccion();
                    objSeleccion.Nombre = item.nombre;
                    objSeleccion.Jugadores = new List<Jugador>();
                    try
                    {
                        foreach (var jugador in item.jugadores)
                        {                         
                            Jugador objJugador = new Jugador();
                            objJugador.Nombre = jugador.nombre;
                            objJugador.Edad = jugador.edad;
                            objJugador.Posicion = jugador.posicion;
                            objJugador.Ataque = jugador.ataque;
                            objJugador.Defensa = jugador.defensa;
                            objJugador.Goles = jugador.goles;
                            objJugador.Asistencias = jugador.asistencias;                           
                            objSeleccion.Jugadores.Add(objJugador);
                        }
                    }
                    catch (System.Exception ex)
                    {
                        Console.WriteLine(ex);
                    }
                    selecciones.Add(objSeleccion);
                }
            };
            return selecciones;
        }
        #endregion Methods

    }
}