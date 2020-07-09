#define LINKEDQUEUET7
#define LINKEDQUEUET7

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue Queue;
typedef struct Node Node;

struct Node{
   int item;
   Node * next; 
};

struct Queue{
   Node *front, *rear;
   int n;
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
   return x -> n;
}

int total( Queue * x ){
   Node * y = x->front;
   int total = 0;
   while( y ){
      total += y->item;
      y = y -> next;
   }

   return total;
}
 
void clear( Queue * x ){
   while( !x -> empty( x ) ) x -> delete( x );
   return;
}

void putFront( Queue * x, int e ){
   putAfter( x, 0, e);
   return;
}

void putAfter( Queue * x, int p, int e ){
   int i;
   Node * y = malloc( sizeof( Node ) );
   y -> item = e;
   if( p == 0 ){
      y -> next = x -> front;
      x -> front = y;
   }else{
      Node * z = x -> front;
      for( i = 0; i < p - 1; i++ )
         z = z -> next;
      y -> next = z -> next;
      z -> next = y;
    }
   x -> n++;
   return;
}

void replaceFront( Queue * x, int e ){
   x -> front -> item = e;
   return;
}

int getRandom( Queue * x ){
   int i, s = rand() % x -> n;
   Node * p = x -> front;
   for( i = 0; i < s; i++)
      p = p -> next;
 
   return p -> item;
}

void putRandom( Queue * x, int a, int b ){
   x -> put( x, a + rand() % ( b - a + 1 ) );
   return;
}

void swap( Queue * x, int a, int b ){
   int i, temp;
   Node * y = x -> front;
   for( i = 0; i < a; i++ )
   y = y -> next;

   Node * z = x -> front;
   for( i = 0; i < b; i++ )
   z = z -> next;

   temp = y -> item;
   y -> item = z -> item;
   z -> item = temp;

   return;
}

void reverse( Queue * x ){
   int i;
   for( i = 0; i < x -> n/2; i++ )
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
   FILE * f = fopen( fn, "wb");
   int temp[ x -> n ], cont = 0;
   Node * y = x->front;
   while( y ){
      temp[cont ++ ] = y->item ;
      y = y->next;
   }
   fwrite( &x->n, sizeof( int ), 1, f);
   fwrite( temp, sizeof( temp ), 1, f);
   fclose( f );
   return;
}

void load( Queue * x, char * fn ){   
   FILE * f = fopen( fn, "rb");
   int z, j;
   fread( &z, sizeof( int ), 1, f);
   int temp[ z ];
   fread( temp, sizeof( temp ), 1, f);
   fclose( f );
   x -> clear( x );
   for( j = 0; j < z; j++ )
      x -> put(x, temp[ j ]);
   return;
}

void put( Queue * x, int e ){
   Node * y = malloc( sizeof( Node ) );
   y -> item = e;
   y->next = NULL;
   if( empty( x ) )
      x -> front = y;
   else
      x -> rear -> next = y;
   x -> rear = y;
   x -> n++;
   return;
}

void delete( Queue * x ){
   if( empty( x ) ){
      fprintf( stderr, "Error: Queue is empty\n" );
      return;
   }
   Node * y = x -> front;
   x -> front = x -> front -> next;
   free( y );
   x -> n--;
   return;
}

int getFront( Queue * x ){
   if( empty( x ) ){
      fprintf( stderr, "Error: Queue is empty\n" );
      exit( 1 );
   }
   return x -> front -> item;
}

int getRear( Queue * x ){
   if( empty( x ) ){
      fprintf( stderr, "Error: Queue is empty\n" );
      exit( 1 );
   }
   return x -> rear -> item;
}

void display( Queue * x ){
   Node * y = x -> front;
   printf( "Queue: [front] " );
   while( y ){
      printf( "%d ", y -> item );
      y = y -> next;
   }
   printf( "[rear]\n" );
   return;
}

int empty( Queue * x ){
   return x -> front == NULL;
}

Queue createQueue( ){
   Queue q;
   q.front = q.rear = NULL;
   q.n = 0;
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
