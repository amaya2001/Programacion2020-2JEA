# pila python

li = [  1, 2, 3, 4, -2, "Hola", 3.0, 10 ]
l = li[ -3: ] # desde el ante-penultimo
li[ -1 ] # el ultimo
li.pop() # Retorna y elimina el item en el index
li.append( 20 ) # Adiciona el valor al final
li.remove( 4 ) # Remueve el valor

if 10 in li:
    li.remove( 10 )

# li.index() # Retorna el indice del valor en la lista
# li.reverse() # cambia de orden la lista 

def f( x, y ):
    return x*y**2

l1 = f( 2, 3 )
#print( l1 )

g = lambda x, y: x*y**3
l2 = g( 2, 3 )
#print( l2 )

# implementar pila con listas y clases

import functools as fu
reduce = fu.reduce
partial = fu.partial

# factorial 

def prod( x, y ): return x*y
l = reduce( prod, ( 1, 2, 3, 8 ) )
# print( l )

def fact( n ):
    if n == 0 or n == 1:
        return 1
    else:
        return reduce( prod, range( 1, n + 1 ) ) # Terminar cuando n = 0

#print( fact( 5 ) )

maxim = lambda x, y: x if x >= y else y
#print( maxim( 3, 4 ) )

#print ( reduce( maxim, ( 3, 6, -2, 9 ) ) )

mini = lambda x, y: x if x <= y else y
#print( reduce( mini, ( 5, 9, 10, 4 ) ) )

triple = partial( prod, 3 )
#print( triple( 8 ) )

def Der1( f, x, h = 0.001 ): return ( f( x + h ) - f( x ) ) / h
#print( Der1( lambda x : 1 / x, 2 ) )

def Der2( f, x, h = 0.001 ): return ( f( x + h ) - f( x - h ) ) / ( 2 * h )
#print( Der2( lambda x : 1 / x, 2 ) )

def Der3( x, y ): return x**3 * y**2
#print( Der2( partial( Der3, 3 ), 2 ) )

seq = [ 0, 1, 2, 3, 4, 5, 6, 7, 9 , 10 ]

result = filter( lambda x : x % 2 == 0 or x % 3 == 0, seq )
print( list( result ) )

def H( x ): return not x % 2 == 0 or x % 3 == 0
print( list( filter( H, ( range( 1, 20 ) ) ) ) )


