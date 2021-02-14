using System;

namespace ArrayForeach
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] elementos = new int[5] {1, 2, 3, 4, 5};
            Console.WriteLine( "Imperativo" ); //WriteLine, le agrega un salto de linea a cada impresion, el write no
            foreach(int elemento in elementos){
                Console.WriteLine( elemento );
            }

            //elementos.foreach (e => Console.WriteLine(e)); -> Forma más avanzada de hacer el foreach -> Declarativa
            Console.WriteLine( "Imperativo" ); // Imperativo -> Como hacer un proceso
            for( int i = 0; i <= elementos.Length; i++ ){
               Console.WriteLine( i ); 
            }

        }
    }
}
