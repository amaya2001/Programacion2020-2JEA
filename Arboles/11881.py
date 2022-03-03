import math 
from sys import stdin
def main():
    eps = 1e-6
    n = int(stdin.readline() )
    while ( n != 0):
        CF = list( map( float, stdin.readline().strip().split() ) )
        high = 10000
        low = -1
        while( high - low > eps ):
            NPB = 0
            mid = ( high + low ) / 2
            for i in range( n + 1 ):
                NPB += CF[ i ]/pow( 1 + mid, i )
            if( NPB > 0):
                low = mid
            else:
                high = mid 

        print( "%.2lf" % mid )
        n = int( stdin.readline() )
main()
