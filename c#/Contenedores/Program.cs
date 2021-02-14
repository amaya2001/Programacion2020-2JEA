using System;
using Contenedores.Objetos;
using System.Collections.Generic;
using System.Collections;

namespace Contenedores
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> listaNombres = new List<string>();
            listaNombres.Add( "Carlos" );
            listaNombres.Add( "Miguel" );
            listaNombres.Add( "Juan" );

            Usuario l = new Usuario() {Nombre = "Loenardo"};

          /*   Console.WriteLine(listaNombres.Count);

            foreach( string i in listaNombres ){
                Console.WriteLine( i );
            }

            Console.WriteLine( listaNombres[ 1 ] ); */

/*             Console.WriteLine( listaNombres.Contains("Juan") );
            Console.WriteLine( listaNombres.Contains("Pedro") ); */
            
            List<Usuario> listaUsuarios = new List<Usuario>()
            {
                new Usuario() { Nombre = "Pepe"},
                new Usuario() { Nombre = "Maria"},
                l,
            };

            /* listaUsuarios.ForEach( p => Console.WriteLine( p.Nombre ) ); */

            listaUsuarios.ForEach( p => {
                string nombreMayuscula = p.Nombre.ToUpper();
                p.Edad = 35;
                Console.WriteLine(nombreMayuscula +" "+ p.Edad);
            } );

                listaUsuarios.ForEach( p => Console.WriteLine( p.Nombre ) );
                Console.WriteLine("===============================");
                listaUsuarios.Remove(l);
                listaUsuarios.ForEach( p => Console.WriteLine( p.Nombre ) );
                Console.WriteLine("==============Tupla=================");

                Tuple<int, string, Usuario> codigoUsuario = new Tuple<int, string, Usuario>(2, "123", new Usuario() {Nombre = "luis"});
                Console.WriteLine(codigoUsuario.Item2);
                Tuple<int, string, Usuario> codigo2 = Tuple.Create(2, "123", new Usuario() {Nombre = "luis"}); //Otra forma de crearlo
                //Tuple<int, int, int, string, double, int> test;

                Console.WriteLine("==============Diccionario=================");
                Dictionary<int, string> usuarios = new Dictionary<int, string>();
                usuarios.Add(12, "Lucas");
                usuarios.Add(13, "Cañas");
               // usuarios[32] = "Johana";
/* 
                foreach( KeyValuePair<int, string> kvp in usuarios ){
                    Console.WriteLine("Key = {0}, Value = {1}", kvp.Key, kvp.Value);

                }         */
                string nombre2 = "";
                if(usuarios.TryGetValue(13, out nombre2)){
                    Console.WriteLine("El nombre encontrado es: " + nombre2);
                }else{
                    Console.WriteLine("El nombre no existe");
                }

                Console.WriteLine("==============Cola=================");
                Queue cola1 = new Queue();
                cola1.Enqueue("Oscar");
                cola1.Enqueue("Coco");
                cola1.Enqueue(25.2);

                foreach( object o in cola1 ){
                    Console.WriteLine(o);
                }

                Console.WriteLine("==============Pila=================");

                Stack pila1 = new Stack();
                pila1.Push("Kiko");
                pila1.Push("Nely");
                pila1.Push("12.3");

                foreach( object i in pila1){
                     Console.WriteLine(i);
                }
        }
    }
}
