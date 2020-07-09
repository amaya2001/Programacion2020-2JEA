#ifndef ARRAYQUEUE
#define ARRAYQUEUE

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
   void (*display_q) ( Queue * );
   int (*empty_q) ( Queue * );
   void (*save_q) ( Queue *, char * );
   void (*load_q) ( Queue *, char * );
};

void put( Queue * x, int e ){
   if( x->n == CAP ){
      fprintf( stderr, "Error: Queue is full\n" );
      return;
   }
   x->rear = ( x->rear + 1 ) % CAP;
   x->a[ x->rear ] = e;
   x->n++;
   return;
}

void delete( Queue * x ){
   if( empty_q( x ) ){
      fprintf( stderr, "Error: Queue is empty\n" );
      return;
   }
   x->front = ( x->front + 1 ) % CAP;
   x->n--;
   return;
}

int getFront( Queue * x ){
   if( empty_q( x ) ){
      fprintf( stderr, "Error: Queue is empty\n" );
      exit( 1 );
   }
   return x->a[ ( x->front + 1 ) % CAP ];
}

int getRear( Queue * x ){
   if( empty_q( x ) ){
      fprintf( stderr, "Error: Queue is empty\n" );
      exit( 1 );
   }
   return x->a[ x->rear ];
}

void display_q( Queue * x ){
   int i; 
   printf( "Queue: [front] " );
   for( i = 1; i <= x->n; i++ )
      printf( "%d ", x->a[ ( x->front + i ) % CAP ] );
   printf( "[rear]\n" );
   return;
}

int empty_q( Queue * x ){
   return !x->n;
}

void save_q( Queue * x, char * fn ){
   FILE * f = fopen( fn, "wb" );
   fwrite( x, sizeof( * x ), 1, f );
   fclose( f );
}

void load_q( Queue * x, char * fn ){
   FILE * f = fopen( fn, "rb" );
   fread( x, sizeof( * x ), 1, f );
   fclose( f );   
}


Queue createQueue( ){
   Queue q;
   q.front = q.rear = q.n = 0;
   q.put = &put;
   q.delete = &delete;
   q.getFront = &getFront;
   q.getRear = &getRear;
   q.display_q = &display_q;
   q.empty_q = &empty_q;
   q.save_q = &save_q;
   q.load_q = &load_q;
   return q;
} 

#endif
