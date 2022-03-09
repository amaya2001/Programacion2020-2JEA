class Nodo:
    def __init__( self, dato ):
        self.dato = dato

    def __str__( self):
        return str( self.dato )

n1 = Nodo( 1 )
n2 = Nodo( 2 )
n3 = Nodo( 3 )
n4 = Nodo( 4 )
print( n1, n2, n3, n4 )