from sys import stdin

MAX = 10000
adj = [ [] for i in range( MAX ) ]
visited = [ False for i in range( MAX ) ]
ow = [ MAX ]
valance, n = int(), int()

def dfsAux( v ):
    visited[ v ] = True
    valance += ow[ v ]
    for u in adj[ v ]:
        if visited[ u ] == False:
            dfsAux( u )
    return valance

def dfs():
    global valance 
    for i in range( n ):
        visited[ i ] = False
        
    good = True
    for i in range( n ):
        if visited[ i ] == False:
            valance = 0 
            val = dfsAux( i )
            if val != 0:
                good = False

    if good:
        print( "Possible\n" )
    else:
        print( "Impossible\n" )

def main():
    global n

    line = int( stdin.readline() )
    while( line != 0 ):
        n, m = map ( int, stdin.readline().split() )
        for i in range( n ):
            ow = ( int, stdin.readline() ) 
        for i in range( m ):
            u, v = map( int, stdin.readline().split() )
            adj[ u ].append( v )
            adj[ v ].append( u )
        dfs()
        for i in range( n ):
            adj[ i ].clear()
            ow[ i ] = 0
    line = line - 1
main()