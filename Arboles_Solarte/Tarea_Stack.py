class Stack:
    def __init__( self ):
        self.items = []

    def push( self, x ):
        self.items.append( x )
    
    def empty( self ):
        if len( self.items ) == 0:
            return True
        else:
            return False

    def pop( self ):
        if self.empty() == False:
            return self.items.pop()

    def top( self ):
        return self.items[ -1 ]

    def display( self ):
        print( "[bottom]", self.items, "[top]" )
        return

if __name__ == '__main__':
    p1 = Stack()

    print( p1.empty() )

    p1.push( 1 )
    p1.push( 2 )
    p1.push( 3 )
    p1.push( 4 )
    p1.push( 5 )

    p1.display()

    print( p1.empty() )

    print( "top ->", p1.top() )

    p1.pop()
    p1.display()

    print( "top ->", p1.top() )

    p1.pop()
    p1.display()
    

