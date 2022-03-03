from sys import stdin

def main():
    line = stdin.readline().strip()
    i = 0
    count = 0
    flag = True # Un flag para evitar el usp de break
    while line !="":
        #Aqui empieza
        stack = []
        for i in range(len(line)): 
            count += 1
            if line[ i ] is '(' or line[ i ] is '[' or line[ i ] is '{' or line[ i ] is '<':
                stack.append( line[ i ] )
                if(line[ i ] is '(' and line[ i + 1 ] is '*'):
                    stack.append('x')
                    i += 1
                else:
                    stack.append( line[ i ] )
            elif line[ i ] is ')' or line[ i ] is ']' or line[ i ] is '}' or line[ i ] is '>' or line[ i ] is '*' and line[ i + 1 ] is ')':
                if( line[i] is 'x'): # Saber que ahi en el stack
                    if( stack[ 0 ] != 'x'):
                        flag = False
                    stack.pop()
                    i += 1
                elif( line[i] is ')'):
                    if(stack[ 0 ] != '('):
                        flag = False
                    stack.pop()
                elif( line[i] is ']' ):
                    if( stack[ 0 ] != '[' ):
                        flag = False
                    stack.pop()
                elif( line[i] is '>' ):
                    if( stack[ 0 ] != '<'):
                        flag = False
                    stack.pop()
                elif( line[i] is '}' ):
                    if( stack[ 0 ] != '{' ):
                        flag = False
                    stack.pop()
                if( len( stack ) is 0 ):
                    flag = False
                #print(count)
        #print(stack)
        if ( len( stack ) is not 0 or count < len( line ) ):
            print( "NO", count )
        else:
            print( "YES" )
        line = stdin.readline().strip()
main()
