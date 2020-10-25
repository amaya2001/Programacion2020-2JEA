using System;
using System.Threading;
namespace ControlPanel.Domain
{
    public class PanelDeControl
    {

        public Usuario[] ListaUsuarios = new Usuario[1];
        public Usuario user;
        Bodega bodega;

        public PanelDeControl()
        {
            bodega = new Bodega();
            bodega.Nombre = "Semillero";
            bodega.IdBodega = 1;
        }


        public void menu()
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
                    if (user == null)
                    {
                        Console.WriteLine("  1 Iniciar Sesion");
                    }
                    else
                    {
                        Console.ForegroundColor = ConsoleColor.Green;
                        Console.WriteLine("  Bienvenido: " + ListaUsuarios[0].Nombre);
                        Console.ForegroundColor = ConsoleColor.White;
                    }
                    Console.WriteLine("  2 Crear usuarios");
                    Console.WriteLine("  3 Ver Usuarios");
                    Console.WriteLine("  4 Crear Semillas");
                    Console.WriteLine("  5 Lista de Semillas");
                    Console.WriteLine("  6 Regar Semillas");
                    Console.WriteLine("  7 Salir");
                    Console.WriteLine("----------- Menu Panel de Control ----------");
                    if (opc == 0)
                    {
                        Console.Write("Digite Opcion: ");
                        opc = int.Parse(Console.ReadLine());
                    }
                    switch (opc)
                    {
                        case 1:
                            Login();
                            mensaje = "";
                            opc = 0;
                            break;
                        case 2:
                            CrearUsuario();
                            if (ListaUsuarios[0] != null)
                            {
                                mensaje = "Usuario Creado.!";
                            }
                            opc = 0;
                            break;
                        case 3:
                            mensaje = "";
                            VerUsuario();
                            opc = 0;
                            break;
                        case 4:
                            mensaje = "";
                            CrearSemilla();
                            opc = 0;
                            break;
                        case 5:
                            mensaje = "";
                            ListarSemillas();
                            opc = 0;
                            break;
                        case 6:
                            mensaje = "";
                            RegarSemillas();
                            opc = 0;
                            break;
                        case 7:
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

        public void Login()
        {
            Console.Clear();
            Console.WriteLine("Inicio de session");
            Console.Write("Ingrese Clave: ");
            int clave = int.Parse(Console.ReadLine());
            if (ListaUsuarios[0] != null)
            {
                if (clave == ListaUsuarios[0].Clave)
                {
                    user = ListaUsuarios[0];
                }
                else
                {
                    Console.WriteLine("El usuario no existe, presione una tecla para continuar");
                    Console.ReadLine();
                }
            }
            else
            {
                Console.WriteLine("No hay usuarios en la base de datos, presione una tecla para continuar");
                Console.ReadLine();
            }


        }


        public void CrearUsuario()
        {
            bool continuar = true;
            do
            {
                Console.Clear();
                try
                {
                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.WriteLine("----------- Menu Crear Usuario ----------");
                    Console.WriteLine("1 Crear");
                    Console.WriteLine("2 Regresar");
                    Console.WriteLine("----------- Menu Crear Usuario ----------");
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.WriteLine("Seleccione una opcion del menu");
                    string opc = Console.ReadLine();
                    switch (opc)
                    {
                        case "1":
                            Console.WriteLine();
                            Console.Write("Digite el  Nombre: ");
                            string nombre = Console.ReadLine();
                            Console.Write("Digite la clave: ");
                            string clave = Console.ReadLine();
                            Console.Write("Es Administrador? S/N : ");
                            string admin = Console.ReadLine();
                            Console.Write("Desea Guardar ? S/N : ");
                            string save = Console.ReadLine();
                            if (save.Equals("S"))
                            {
                                Usuario user = new Usuario();
                                user.Nombre = nombre;
                                user.Clave = int.Parse(clave);
                                user.Administrador = (admin.Equals("S")) ? true : false;
                                ListaUsuarios[0] = user;
                                continuar = false;
                            }
                            break;
                        case "2":
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
        }


        public void VerUsuario()
        {
            Console.Clear();
            bool continuar = true;
            do
            {

                try
                {
                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.WriteLine("----------- Menu Lista Usuario ----------");
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.WriteLine("Nombre | Admin?");
                    int i;
                    for (i = 0; i < ListaUsuarios.Length; i++)
                    {
                        Console.WriteLine(ListaUsuarios[i].Nombre + " | " + ListaUsuarios[i].Administrador);
                    }
                    Console.WriteLine("Regresar ? S/N");
                    string opc = Console.ReadLine();
                    if (opc.Equals("S"))
                    {
                        continuar = false;
                    }
                }
                catch (Exception ex)
                {
                    Console.Write("Error: " + ex);

                }

            } while (continuar);
        }

        public void CrearSemilla()
        {

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
                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.WriteLine("----------- Menu Crear Semilla ----------");
                    Console.WriteLine("1 Crear");
                    Console.WriteLine("2 Regresar");
                    Console.WriteLine("----------- Menu Crear Semilla ----------");
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.WriteLine("Seleccione una opcion del menu");
                    string opc = Console.ReadLine();
                    switch (opc)
                    {
                        case "1":
                            Console.WriteLine();
                            Console.Write("Digite el  Tipo: ");
                            string tipo = Console.ReadLine();
                            Console.Write("Digite la Cantidad de agua: ");
                            string CantidadAgua = Console.ReadLine();
                            Console.Write("Digite la Cantidad de sombra: ");
                            string CantidadSombra = Console.ReadLine();
                            Console.Write("Desea Guardar ? S/N : ");
                            string save = Console.ReadLine();
                            if (save.Equals("S"))
                            {
                                Semilla s = new Semilla();
                                s.Tipo = tipo;
                                s.CantidadAgua = int.Parse(CantidadAgua);
                                s.CantidadSombra = int.Parse(CantidadSombra);
                                s.Id = (bodega.getListSemillas().Length) + "";
                                bodega.addSemilla(s);
                                mensaje = "Semilla Creada";
                            }
                            else
                            {
                                mensaje = "Se cancelo la accion";
                            }
                            break;
                        case "2":
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
                    continuar = false;
                }

            } while (continuar);
        }


        public void ListarSemillas()
        {
            Console.Clear();
            bool continuar = true;
            do
            {

                try
                {
                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.WriteLine("----- Menu Lista Semillas Bodega: " + bodega.Nombre + " ------");
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.WriteLine(" ID | Tipo | Cantidad Agua | Cantidad Sombra");
                    Semilla[] ListaSemillas = bodega.getListSemillas();
                    int i;
                    for (i = 0; i < ListaSemillas.Length - 1; i++)
                    {
                        Console.WriteLine(" " + ListaSemillas[i].Id + " | " + ListaSemillas[i].Tipo + " | " + ListaSemillas[i].CantidadAgua + " | " + ListaSemillas[i].CantidadSombra);
                    }
                    Console.WriteLine(" Total Semillas: " + ListaSemillas.Length);
                    Console.WriteLine("Regresar ? S/N");
                    string opc = Console.ReadLine();
                    if (opc.Equals("S"))
                    {
                        continuar = false;
                    }
                }
                catch (Exception ex)
                {
                    Console.Write("Error: " + ex);

                }

            } while (continuar);
        }


        public void RegarSemillas()
        {

            bool continuar = true;
            string mensaje = "";
            do
            {

                try
                {
                    Console.Clear();
                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.WriteLine("----- Sistema de Riego de Semillas Bodega: " + bodega.Nombre + " ------");
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.WriteLine("----------- Menu  ----------");
                    Console.WriteLine("1 Regar Una semilla");
                    Console.WriteLine("2 Regar Todas las Semillas");
                    Console.WriteLine("3 Regresar");
                    Console.WriteLine("----------- Menu  ----------");
                    Console.WriteLine(" ID | Tipo | Cantidad Agua | Cantidad Sombra");
                    Semilla[] ListaSemillas = bodega.getListSemillas();
                    int i;
                    for (i = 0; i < ListaSemillas.Length - 1; i++)
                    {
                        Console.WriteLine(" " + ListaSemillas[i].Id + " | " + ListaSemillas[i].Tipo + " | " + ListaSemillas[i].CantidadAgua + " | " + ListaSemillas[i].CantidadSombra);
                    }
                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.WriteLine(mensaje);
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.Write("Digite una opcion: ");
                    string opc = Console.ReadLine();
                    switch (opc)
                    {
                        case "1":
                            Console.Write("Digita el Id de la semilla: ");
                            int id = int.Parse(Console.ReadLine());
                            Semilla semilla = ListaSemillas[id - 1];
                            Console.WriteLine("Semilla Seleccionada: " + semilla.Tipo);
                            Console.WriteLine("Iniciar Proceso de Riego, cantiad de agua: " + semilla.CantidadAgua + "lts");
                            Console.ForegroundColor = ConsoleColor.Green;
                            for (int j = 0; j < semilla.CantidadAgua; j++)
                            {
                                Console.Write("**");
                                Thread.Sleep(400);
                            }
                            mensaje = "[ Semilla " + semilla.Tipo + " Regada Completamente ]";
                            break;
                        case "2":
                            Console.WriteLine("Iniciar Proceso de Riego, Todas las semillas serán regadas");

                            for (int z = 0; z < bodega.getListSemillas().Length - 1; z++)
                            {

                                Console.WriteLine("Semilla: " + bodega.getListSemillas()[z].Tipo);
                                Console.WriteLine("Iniciar Proceso de Riego, cantiad de agua: " + bodega.getListSemillas()[z].CantidadAgua + "lts");
                                Console.ForegroundColor = ConsoleColor.Green;
                                for (int j = 0; j < bodega.getListSemillas()[z].CantidadAgua; j++)
                                {

                                    Console.Write("**");
                                    Thread.Sleep(400);
                                }
                                Console.ForegroundColor = ConsoleColor.White;
                                Console.WriteLine();
                            }

                            mensaje = "[ Todas las semillas fueron regadas completamente ]";
                            break;
                        case "3":
                            continuar = false;
                            break;
                    }
                }
                catch (Exception ex)
                {
                    Console.Write("Error: " + ex);

                }

            } while (continuar);
        }

    }

}