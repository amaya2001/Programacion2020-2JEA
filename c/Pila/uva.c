#include <stdio.h>
#define CAP 100000

typedef  struct Stack stack;

struct Stack 
{
    char a[ CAP ];
    int top;
    void (*push) ( Stack *, char);
};

void push( Stack * x, int e ){
   if( x->top == CAP - 1 ){
      fprintf( stderr, "Error: stack is full\n" );
      return;
   }
   x->a[ ++x->top ] = e;
   return;
}

Stack createStack( ){
   Stack s;
   s.top = -1;
   s.push = &push;
   return s;
}

int main(){
    char arreglo[] = {};
}

