import math

class Vectores:
    def __init__( self, a , b):
        self.a = a
        self.b = b
        self.v = [ a, b ]

    def metodo( self ):
        a = self.a
        b = self.b
        return math.sqrt( (a**2) + ( b**2 ) )

    def suma( self, w ):
        return sum( self.v, w )

    def dot( self, w ):
        return self.v * w

    def nortax( self, w ):
        return sum( abs( self.v ), abs( w ) )





     
    