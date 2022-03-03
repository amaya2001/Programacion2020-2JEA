import math 
from sys import stdin
def main():
    case = 1
    line = stdin.readline().split(":")
    while ( line != ""):
        eps = 1e-9
        high = 200
        low = 0
        #print( line[ 0 ] )
        #print( line[ 1 ]  )
        a = int( line[ 0 ] )
        b = int( line[ 1 ] )
        while( high - low > eps ):
            mid = ( high + low ) / 2
            rad = math.sqrt( a ** 2 + b ** 2 )/2
            arc = 2 * rad * math.acos(mid / ( 2 * rad ) )
            perim = 2 * mid + 2 * arc 
            if( perim > 400 ):
                high = mid 
            else:
                low = mid 
        print( "Case %d: %.10lf %.10lf" % ( case, mid, b * mid ) )
        case += 1
        line = stdin.readline().split(":")
main()

    

