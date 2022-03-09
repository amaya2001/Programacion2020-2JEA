dic = { 'x':2,'edad': 5, 'nombre':'juan', 3: 1 }

#print( dic.keys() )
#print( dic.get( 3 ), dic[ 3 ] )
#print( dic.items() )

dic.setdefault( 9 )
#print( dic )

dic1 = {}

word = "abracadabra"
for i in word:
    if not ( i in dic1 ):
        dic1.setdefault( i, 1 )
    else:
        dic1[ i ] += 1

#print( dic1 )

dic2 = {}

word = "abracadabra"
for i in word:
    dic2[ i ] = dic2.get( i, 0 ) + 1

#print( dic2 )

cache = { 0:1, 1:1 }
def fib( n ):
    if n in cache:
        return cache[ n ]
    else:
        val = fib( n - 1 ) + fib( n - 2 )
        cache.setdefault( n, val )
        return cache[ n ]

#print( fib( 80 ) ) 

class fun:
    def __init__( self, m, b ):
        self.m = m
        self.b = b
    
    def value( self, x ):
        m = self.m
        b = self.b
        return m * x + b

    def cortx( self ):
        return self.b / self.m

    def __call__( self, x ):
        return self.value( x )

pendiente = fun( 3, 4 )
#print( pendiente.value( 5 ) )

print( pendiente( 5 ) )

def puntoPendiente( x1, y1, x2, y2 ):
    m = ( y2 - y1 ) / ( x2 - x1 )
    b = y1 - m * x1
    return fun( m, b )

linea2 = puntoPendiente( 2, 4, 4, 8 )
print( linea2( 8 ) )