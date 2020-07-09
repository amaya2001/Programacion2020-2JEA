#define ARRAYQUEUET7
#define ARRAYQUEUET7

#include <stdio.h>
#include <stdlib.h>
#define CAP 100

typedef struct Queue Queue;

struct Queue{
   int a[ CAP ];
   int front, rear, n;
   void (*put) ( Queue *, int );
   void (*delete) ( Queue * );
   int (*getFront) ( Queue * );
   int (*getRear) ( Queue * );
   void (*display) ( Queue * );
   int (*empty) ( Queue * );
   int (*size) ( Queue * );
   int (*total) ( Queue * );
   void (*clear) ( Queue * );
   void (*putFront) ( Queue *, int );
   void (*putAfter) ( Queue *, int, int );
   void (*replaceFront) ( Queue *, int ); 
   int (*getRandom) ( Queue * );
   void (*putRandom) ( Queue *, int, int );
   void (*reverse) ( Queue * );
   void (*shuffle) ( Queue * );
   void (*save) ( Queue *, char * );
   void (*load) ( Queue *, char * );
};

int size( Queue * x ){
   int i, conteo = 0;
   for( i = 1; i <= x->n; i++ )
      conteo ++;

   return conteo;
}

int total( Queue * x ){
   int i, total = 0;
   for( i = 1; i <= x->n; i++ )
      total += x->a[ ( x->front + i ) % CAP ];

   return total;
}

void clear( Queue * x ){
   int i, t = x->n;
   for( i = 0; i < t; i++ )
      delete( x );
   return;
}

void putFront( Queue * x, int e ){
   putAfter( x, 0, e);
   return;
}

void putAfter( Queue * x, int p, int e ){
      int i, s = x-> front + 1;
   for( i = x -> n - 1; i >= p; i-- )
      x -> a[ ( s + i + 1 ) % CAP ] = x -> a[ ( s + i )% CAP ];
   x -> a[ ( s + p ) % CAP ] = e;
   x -> n++;
   return;
}

void replaceFront( Queue * x, int e ){
   x -> a[ ( x -> front + 1 ) % CAP ] = e;
   return;
}

int getRandom( Queue * x ){
   return x->a[(x->front + 1 + rand() % x->n) % CAP];
}

void putRandom( Queue * x, int a, int b ){
   x -> put( x, a + rand() % ( b - a + 1 ) );
   return;
}

void swap( Queue * x, int a, int b ){
   int s = x -> front + 1;
   int temp = x -> a[ ( s + a ) % CAP ];
   x-> a[ ( s + a ) % CAP ] = x-> a[ ( s + b ) % CAP ];
   x -> a[ ( s + b ) % CAP ] = temp;
   return;
}

void reverse( Queue * x ){
   int i;
   for( i=0; i < x -> n / 2; i++ )
      swap( x, i, x -> n - i - 1 );
   return;
}

void shuffle( Queue * x ){
   int i;
   for( i = 0; i < 30; i++ )
      swap( x, rand() % x -> n, rand() % x -> n );
   return;
}

void save( Queue * x, char * fn ){
   FILE * f = fopen( fn, "wb" );
   fwrite( x, sizeof( Queue ), 1, f );
   fclose( f );
   return;
}

void load( Queue * x, char * fn ){
   FILE * f = fopen( fn, "rb" );
   fread( x, sizeof( Queue ), 1, f);
   fclose( f );
   return;
}

void put( Queue * x, int e ){
   if( x->n == CAP ){
      fprintf( stderr, "Error: Queue is full\n" );
      return;
   }
   x -> rear = ( x -> rear + 1 ) % CAP;
   x->a[ x -> rear ] = e;
   x-> n++;
   return;
}

void delete( Queue * x ){
   if( empty( x ) ){
      fprintf( stderr, "Error: Queue is empty\n" );
      return;
   }
   x -> front = ( x -> front + 1 ) % CAP;
   x -> n--;
   return;
}

int getFront( Queue * x ){
   if( empty( x ) ){
      fprintf( stderr, "Error: Queue is empty\n" );
      exit( 1 );
   }
   return x -> a[ ( x -> front + 1 ) % CAP ];
}

int getRear( Queue * x ){
   if( empty( x ) ){
      fprintf( stderr, "Error: Queue is empty\n" );
      exit( 1 );
   }
   return x -> a[ ( x -> rear + 1 ) % CAP ];
}

void display( Queue * x ){
   int i; 
   printf( "Queue: [front] " );
   for( i = 1; i <= x->n; i++ )
      printf( "%d ", x -> a[ ( x -> front + i ) % CAP ] );
   printf( "[rear]\n" );
   return;
}

int empty( Queue * x ){
   return !x -> n;
}

Queue createQueue( ){
   Queue q;
   q.front = q.rear = q.n = 0;
   q.put = &put;
   q.delete = &delete;
   q.getFront = &getFront;
   q.getRear = &getRear;
   q.display = &display;
   q.empty = &empty;
   q.size=&size;
   q.total=&total;
   q.clear=&clear;
   q.putFront=&putFront;
   q.putAfter=&putAfter;
   q.replaceFront=&replaceFront;
   q.getRandom=&getRandom;
   q.putRandom=&putRandom;
   q.reverse=&reverse;
   q.shuffle=&shuffle;
   q.save=&save;
   q.load=&load;
   return q;
} 

