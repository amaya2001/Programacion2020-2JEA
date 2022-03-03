using System;
using System.Collections.Generic;
using System.IO;
using Newtonsoft.Json;
using System.Linq;
using Excepciones.CustomExceptions;
namespace linq.Torneo
{
    public class Menu
    {

        List<Partido> partidos = new List<Partido>();

        public Menu()
        {

        }

        public void PantallaMenu()
        {
            int opc = 0;
            bool continuar = true;
            string mensaje = "";
            do
            {
                Console.Clear();
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine(mensaje);
                Console.ForegroundColor = ConsoleColor.White;
                try
                {
                    Console.WriteLine("----------- Menu Panel de Control ----------");
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.WriteLine("Presione (Enter) cada vez que digite en la consola..!");
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.WriteLine("---------Seleccione una opcion del menu---------");
                    Console.WriteLine("  1 Crear Seleccion");
                    Console.WriteLine("  2 Crear Partidos");
                    Console.WriteLine("  3 Iniciar Partidos Programados");
                    Console.WriteLine("  4 Salir");
                    Console.WriteLine("----------- Menu Panel de Control ----------");
                    if (opc == 0)
                    {
                        Console.Write("Digite Opcion: ");
                        opc = int.Parse(Console.ReadLine());
                    }
                    switch (opc)
                    {
                        case 1:
                            mensaje = CrearSeleccion();
                            opc = 0;
                            break;
                        case 2:
                            mensaje = CrearPartidos();
                            opc = 0;
                            break;
                        case 3:
                            mensaje = EjecutarPartidosProgramados();
                            opc = 0;
                            break;
                        case 4:
                            Console.Clear();
                            Console.ForegroundColor = ConsoleColor.Red;
                            Console.WriteLine("Saliste del sistema");
                            Console.ForegroundColor = ConsoleColor.White;
                            opc = 0;
                            continuar = false;
                            break;
                        default:
                            Console.Write("Selecciona una opcion valida: ");
                            opc = int.Parse(Console.ReadLine());
                            break;
                    }


                }
                catch (Exception ex)
                {
                    Console.Write("   Selecciona una opcion valida " + ex);

                }

            } while (continuar);
        }



        public string CrearSeleccion()
        {
            bool continuar = true;
            string msg = "";
            do
            {
                Console.Clear();
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine(msg);
                Console.ForegroundColor = ConsoleColor.White;
                try
                {
                    RepositorioDatos Datos = new RepositorioDatos();
                    List<Seleccion> Selecciones = Datos.Selecciones;
                    Console.WriteLine("**********************************************************************");
                    Console.ForegroundColor = ConsoleColor.Yellow;
                    Console.WriteLine("Listado de Selecciones");
                    Console.ForegroundColor = ConsoleColor.White;
                    int id = 1;
                    foreach (var _seleccion in Selecciones)
                    {
                        Console.WriteLine(" [ " + id + " , " + _seleccion.Nombre + " , Total Jugadores: " + _seleccion.Jugadores.Count + " ]");
                        id++;
                    }
                    Console.WriteLine("**********************************************************************");
                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.WriteLine("----------- Menu Crear Seleccion ----------");
                    Console.WriteLine("1 Crear");
                    Console.WriteLine("2 Agregar Jugadores");
                    Console.WriteLine("3 Regresar");
                    Console.WriteLine("----------- Menu Crear Seleccion ----------");
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.Write("Seleccione una opcion del menu: ");
                    string opc = Console.ReadLine();
                    switch (opc)
                    {
                        case "1":
                            Console.WriteLine();
                            Console.Write("Digite el  Nombre: ");
                            string nombre = Console.ReadLine();
                            Console.Write("Desea Agregar Jugadores? S/N : ");
                            string adJugador = Console.ReadLine();
                            Seleccion s = new Seleccion();
                            s.Nombre = nombre;
                            s.PuntosTotales = 0;
                            s.GolesTotales = 0;
                            s.AsistenciasTotales = 0;
                            List<Jugador> jugadoresl = new List<Jugador>();
                            do
                            {
                                Console.Write("Digite el  Nombre Jugador: ");
                                string nombreJugador = Console.ReadLine();
                                Console.Write("Digite la edad: ");
                                string edadJugador = Console.ReadLine();
                                Console.Write("Digite la posicion: ");
                                string posJugador = Console.ReadLine();
                                Console.Write("Digite el ataque: ");
                                string atacJugador = Console.ReadLine();
                                Console.Write("Digite la defensa: ");
                                string defJugador = Console.ReadLine();
                                Console.Write("Digite los goles: ");
                                string golesJugador = Console.ReadLine();
                                Console.Write("Digite las asistencias: ");
                                string asistenciasJugador = Console.ReadLine();

                                Jugador j = new Jugador();
                                j.Nombre = nombreJugador;
                                j.Edad = int.Parse(edadJugador);
                                j.Posicion = int.Parse(posJugador);
                                j.Ataque = double.Parse(atacJugador);
                                j.Defensa = double.Parse(defJugador);
                                j.Goles = int.Parse(golesJugador);
                                j.Asistencias = int.Parse(asistenciasJugador);
                                jugadoresl.Add(j);

                                Console.Write("Desea Agregar otro Jugador? S/N : ");
                                adJugador = Console.ReadLine();

                            } while (adJugador.Equals("S"));

                            s.Jugadores = jugadoresl;
                            Selecciones.Add(s);
                            string texto = JsonConvert.SerializeObject(Selecciones);
                            File.WriteAllText("./selecciones.json", texto);
                            msg = "Seleccion agregada";
                            break;
                        case "2":
                            msg = "";
                            Console.Write("Digite el Id de la Seleccion: ");
                            string idSeleccion = Console.ReadLine();
                            try
                            {
                                Selecciones.ElementAt(int.Parse(idSeleccion) - 1);
                                string newJugador = "S";
                                do
                                {
                                    Console.ForegroundColor = ConsoleColor.Green;
                                    Console.WriteLine(msg);
                                    Console.ForegroundColor = ConsoleColor.White;
                                    Console.Write("Digite el  Nombre Jugador: ");
                                    string nombreJugador = Console.ReadLine();
                                    Console.Write("Digite la edad: ");
                                    string edadJugador = Console.ReadLine();
                                    Console.Write("Digite la posicion: ");
                                    string posJugador = Console.ReadLine();
                                    Console.Write("Digite el ataque: ");
                                    string atacJugador = Console.ReadLine();
                                    Console.Write("Digite la defensa: ");
                                    string defJugador = Console.ReadLine();
                                    Console.Write("Digite los goles: ");
                                    string golesJugador = Console.ReadLine();
                                    Console.Write("Digite las asistencias: ");
                                    string asistenciasJugador = Console.ReadLine();

                                    Jugador j = new Jugador();
                                    j.Nombre = nombreJugador;
                                    j.Edad = int.Parse(edadJugador);
                                    j.Posicion = int.Parse(posJugador);
                                    j.Ataque = double.Parse(atacJugador);
                                    j.Defensa = double.Parse(defJugador);
                                    j.Goles = int.Parse(golesJugador);
                                    j.Asistencias = int.Parse(asistenciasJugador);
                                    Selecciones.ElementAt(int.Parse(idSeleccion) - 1).Jugadores.Add(j);
                                    string list = JsonConvert.SerializeObject(Selecciones);
                                    File.WriteAllText("./selecciones.json", list);
                                    Console.Write("Desea Agregar otro Jugador? S/N : ");
                                    newJugador = Console.ReadLine();
                                    msg = "Jugador agregado";

                                } while (newJugador.Equals("S"));

                            }
                            catch (System.Exception)
                            {
                                msg = "Error al agregar jugadores";
                            }
                            break;
                        case "3":
                            continuar = false;
                            break;
                        default:
                            Console.Write("Selecciona una opcion valida: ");
                            opc = Console.ReadLine();
                            break;
                    }
                }
                catch (Exception ex)
                {
                    Console.Write("Error: " + ex);
                }

            } while (continuar);

            return msg;
        }

        public string EjecutarPartidoAmistoso()
        {
            RepositorioDatos Datos = new RepositorioDatos();
            List<Seleccion> Selecciones = Datos.Selecciones;
            Seleccion local = Selecciones.First(s => s.Nombre == "Francia") as Seleccion;
            Seleccion Visitante = Selecciones.FirstOrDefault(s => s.Nombre == "Argentina") as Seleccion;
            Partido partido1 = new Partido(local, Visitante);
            return "Partido Finalizado  " + local.Nombre + " (" + partido1.Resultado() + ") " + Visitante.Nombre;
        }


        public string EjecutarPartidosProgramados()
        {
            RepositorioDatos Datos = new RepositorioDatos();
            List<Seleccion> Selecciones = Datos.Selecciones;
            Sujeto mSujeto = new Sujeto();

            List<Observador> listObserver = new List<Observador>();
            foreach (var objSelecion in Selecciones)
            {
                Observador obj = new Observador(objSelecion.Nombre, mSujeto);
                listObserver.Add(obj);
            }

            if (partidos.Count == 0)
            {
                Console.WriteLine("No hay partidos programados");
            }

            foreach (var partido in partidos)
            {
                Console.WriteLine("**********************************************");
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine(partido.EquipoLocal.Seleccion.Nombre + " VS " + partido.EquipoVisitante.Seleccion.Nombre);
                Console.ForegroundColor = ConsoleColor.White;
                string result = partido.Resultado();
                Console.WriteLine("Partido Finalizado  " + partido.EquipoLocal.Seleccion.Nombre + " (" + result + ") " + partido.EquipoVisitante.Seleccion.Nombre);
                Console.WriteLine("**********************************************");

                int indexLocal = 0;
                for (int i = 0; i < Selecciones.Count; i++)
                {
                    if (Selecciones.ElementAt(i).Nombre.Equals(partido.EquipoLocal.Seleccion.Nombre))
                    {
                        indexLocal = i;
                        break;
                    }
                }
                int indexVisitante = 0;
                for (int i = 0; i < Selecciones.Count; i++)
                {
                    if (Selecciones.ElementAt(i).Nombre.Equals(partido.EquipoVisitante.Seleccion.Nombre))
                    {
                        indexVisitante = i;
                        break;
                    }
                }
                int puntosLocal = 1;
                int puntosVisitante = 1;
                if (partido.EquipoLocal.Goles > partido.EquipoVisitante.Goles)
                {
                    puntosLocal = 3;
                }
                else
                {
                    puntosVisitante = 3;
                }
                mSujeto.ActualizarInfoSeleccion(Selecciones, indexLocal, puntosLocal, partido.EquipoLocal.Goles);
                mSujeto.ActualizarInfoSeleccion(Selecciones, indexVisitante, puntosVisitante, partido.EquipoVisitante.Goles);
            }

            partidos.Clear();

            Console.WriteLine("Presione una tecla para terminar");
            Console.ReadLine();
            return "Todos los patidos se llevaron a cabo";
        }

        public string CrearPartidos()
        {
            string newpartido = "S";
            string msg = "";
            try
            {
                RepositorioDatos Datos = new RepositorioDatos();
                List<Seleccion> Selecciones = Datos.Selecciones;
                do
                {
                    Console.Clear();
                    Console.ForegroundColor = ConsoleColor.Yellow;
                    Console.WriteLine("///////////////////////////////////////////////////////////");
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.WriteLine("Partidos Programados:");
                    foreach (var partido in partidos)
                    {
                        Console.WriteLine(partido.EquipoLocal.Seleccion.Nombre + " VS " + partido.EquipoVisitante.Seleccion.Nombre);
                    }
                    Console.ForegroundColor = ConsoleColor.Yellow;
                    Console.WriteLine("///////////////////////////////////////////////////////////");
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.WriteLine(msg);
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.WriteLine("**********************************************************************");
                    Console.ForegroundColor = ConsoleColor.Yellow;
                    Console.WriteLine("Listado de Selecciones");
                    Console.ForegroundColor = ConsoleColor.White;
                    int id = 1;
                    foreach (var _seleccion in Selecciones)
                    {
                        Console.WriteLine(" [ " + id + " , " + _seleccion.Nombre + " , Total Jugadores: " + _seleccion.Jugadores.Count + " ]");
                        id++;
                    }
                    Console.WriteLine("**********************************************************************");
                    Console.Write("Digite del id de la seleccion local: ");
                    int idLocal = int.Parse(Console.ReadLine());
                    Console.Write("Digite del id de la seleccion Visitante: ");
                    int idVisitante = int.Parse(Console.ReadLine());
                    try
                    {
                        partidos.Add(new Partido(Selecciones.ElementAt(idLocal - 1), Selecciones.ElementAt(idVisitante - 1)));
                    }
                    catch (NoExisteElemento ex)
                    {
                        ex.elemento = (idLocal - 1) + "," + (idVisitante - 1);
                        Console.WriteLine(ex);
                        msg = ex.ToString();
                    }

                    Console.ForegroundColor = ConsoleColor.White;
                    Console.Write("Desea crear otro partido? S/N ");
                    newpartido = Console.ReadLine();
                    if (newpartido.Equals("") || newpartido == null)
                    {
                        msg = "Si no seleccionas S/N el sistema sale de la opcion crear partidos..!";
                        OpcionNoValida ex = new OpcionNoValida(newpartido);
                        ex.opcion = newpartido;
                        newpartido = "N";
                    }


                } while (newpartido.Equals("S"));

                msg = partidos.Count.ToString();

            }
            catch (InvalidOperationException)
            {

                Console.WriteLine("No existe la opcion" + newpartido);
            }
            return "Partidos Programados con exito..! [" + msg + "]";
        }


    }




}