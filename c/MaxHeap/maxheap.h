#ifndef MAXHEAP
#define MAXHEAP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CAP 100

typedef struct Heap Heap;
typedef struct Persona Persona;
typedef Persona type_d;

struct Persona{
   char nombre[ 20 ]; 
   int id, sev;
};


typedef enum estadoDeAnimo{
	NADA = 1, POCO = 2, MODERADO = 3, MUCHO = 4 // Se les da un valor numerico porque por defecto los enums empiezan desde 0 y yo nacesito que empiezen desde 1
}estadoDeAnimo_e;

struct Heap{
   type_d a[ CAP + 1]; 
   int n;
   void (*put) ( Heap *, type_d );
   void (*delete) ( Heap * );
   type_d (*top) ( Heap * );
   type_d (*getFront) ( Heap * );
   int (*initialize) ( Heap *, type_d *, int );
   void (*display) ( Heap * );
   int (*empty) ( Heap * );
   void (*clear) ( Heap * );
   void(*buscarId) (Heap *, int );
   void(*buscarNombre) (Heap *, char * );
   void (*save) ( Heap *, char * );
   void (*load) ( Heap *, char * );
};

void put( Heap * x, type_d e ){
   if( x->n == CAP ){
      fprintf( stderr, "Error: Heap is full\n" );
      return;
   }
   int p = ++x->n;
   while( p != 1 && x->a[ p / 2 ].sev < e.sev ){
      x->a[ p ] = x->a[ p / 2 ];
      p /= 2;
   }
   x->a[ p ] = e;    
}
	
estadoDeAnimo_e mostrarAnimo(){
	estadoDeAnimo_e animoUsuario;

	printf( "Ingrese un numero del 1 al 4 que refleje\n" );
        printf( "la cantidad de dolor que sientes: " );
	scanf( "%d", &animoUsuario );

	return animoUsuario;
}

int empty( Heap * x ){
   return !x->n;
}

void delete( Heap * x ){
   if( empty( x ) ){
      fprintf( stderr, "Error: Heap is empty\n" );
      return;
   }
   type_d e = x->a[ x->n-- ];
   int p = 1, child = 2;
   while( child <= x->n ){
      if( child < x->n && x->a[ child ].sev < x->a[ child + 1 ].sev )
         child++;
      if( e.sev >= x->a[ child ].sev )
         break;
      x->a[ p ] = x->a[ child ];
      p = child;
      child *= 2;
   }
   x->a[ p ] = e;
}

type_d top( Heap * x ){
   if( empty( x ) ){
      fprintf( stderr, "Error: Heap is empty\n" );
      exit( 1 );
   }
   printf( "(%d %s %d)\n", x->a[ 1 ].sev, x->a[ 1 ].nombre, x->a[ 1 ].id );
}

type_d getFront( Heap * x ){
   if( empty( x ) ){
      fprintf( stderr, "Error: Heap is empty\n" );
      exit( 1 );
   }
   return x->a[ 1 ];
}

int initialize( Heap * x, type_d * b, int size ){
   int i, root, child;
   type_d rootElement;
   for( i = 0; i < size; i++ )
      x->a[ i ] = b[ i ];
      x->n = size;
   for( root = x->n / 2; root >= 1; root-- ){
      rootElement = x->a[ root ];
      child = 2 * root;
   while( child <= x->n ){
      if( child < x->n && x->a[ child ].sev < x->a[ child + 1 ].sev )
         child++;
      if( rootElement.sev >= x->a[ child ].sev )
      break;
      x->a[ child / 2 ] = x->a[ child ];
      child *= 2;
      }
      x->a[ child / 2 ] = rootElement;
   }
}

void display( Heap * x ){
   int i; 
   Persona p;
   printf( "Heap: " );
   Heap t = *x;
   while( !t.empty( &t ) ){
      p = t.getFront( &t );
      printf( "(%s, %d, %d )", p.nombre, p.id, p.sev );
      t.delete( &t );
   }  
   printf( "\n" );
   return;
}

void clear( Heap * x ){
   int i, t = x->n;
   for( i = 0; i < t; i++ )
      delete( x );
   return;
}

void buscarId( Heap * x, int temp ){
   int i;
   for( i = 0; i < CAP; i++ ){
      if( temp == x -> a[ i ].id ){
         printf( "(%s, %d) es el usuario a buscar!\n", x->a[ i ].nombre, x->a[ i ].sev );
         return;
      }
  
   }
   printf( "El id buscado no pertenece a nadie.\n" );
}


void buscarNombre( Heap * x, char * temp ){
   char nombreNuevo[ 20 ];
   int i;

   for( i = 0; i < CAP; i++ ){
      if( strcmp(x->a[ i ].nombre, temp ) == 0 ){
         printf( "(%s, %d, %d) es el usuario a buscar!\n", x->a[ i ].nombre, x->a[ i ].id,  x->a[ i ].sev );
         return;
      }
  
   }
   printf( "El nombre buscado no pertenece a nadie.\n" );
}

void save( Heap * x, char * fn ){
   FILE * f = fopen( fn, "wb" );
   fwrite( x, sizeof( * x ), 1, f );
   fclose( f );
}

void load( Heap * x, char * fn ){
   FILE * f = fopen( fn, "rb" );
   fread( x, sizeof( * x ), 1, f );
   fclose( f );   
}

Heap createHeap( ){
   Heap h;
   h.n = 0;
   h.put = &put;
   h.delete = &delete;
   h.top = &top;
   h.getFront = &getFront;
   h.initialize = &initialize;
   h.display = &display;
   h.empty = &empty;
   h.clear = &clear;
   h.buscarId = &buscarId;
   h.buscarNombre = &buscarNombre;
   h.save = &save;
   h.load = &load;
   return h;
} 

#endif