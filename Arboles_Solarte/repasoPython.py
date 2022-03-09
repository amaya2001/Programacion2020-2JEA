# ===== Listas -> El indice de una lista empieza desde 0 hasta n, ciendo n > 0

# Declaracion
from encodings import utf_8


l = [ 2,"tres", True, [ "uno", 10 ], 6, 10 ]

# Imprimir un elemento en especifico
l2 = l[ 1 ]

# Copia lo que este en l del indice 0 hasta el indice 3 en l3
l3 = l[ 0:3 ]

# Copia lo que este en ldel indice 0 hasta el indice 3 de dos en dos en l3
l4 = l[ 0:3:2 ] 

# Recorre la lista, y cambia los valores del indice 0,1 por un 4,3 respectivamente
l[ 0:1 ] = [ 4,3 ]

# Imprime la ultima posicion, y asi sucesivamente 
l5 = l[ -1 ] 

# =========== Diccionario -> se declara con un indicador y el contenido
d = { 'Clave 1': [ 1, 2, 3 ],
        'Clave2': True
}

d[ 'Clave2' ] = False # Asi se cambia el valor asociado a al indicador
 
#print (d[ 'Clave2' ]) -> Imprime el valor asociado al indicador

# ====== Operadores relacionales 
v = 5
c = 5

r = c == v # c y v son iguales? retorna True
s = c != v # c y v son diferentes? retorna False 

# ==== Sentencias condicionales
edad = 17 
m_edad = 18

if edad >= m_edad:
    print( "Eres mayor de edad" )
    if False:
        print( "Esto se ejecuta siempre que sea mayor de edad" )
    else:
        print( "Cualquier cosa" )
else:
    print( "No eres mayor de edad" ) 
# print( "Esto se ejecuta siempre" )

encoding: utf_8 # para letras no compatibles

if edad >= 0 and edad < 18:
    print ( "eres un nino" )

# ===== Bucles
#while True:
    #print ( "HoLa" ) -> Bucle infinito

edad = 0
while edad <= 20:
    if edad == 15:
        edad = edad + 1 # Sin esta liena, queda en un bloque infinito cuando llega a 15, con ella se salta el 15 y sigue el ciclo
        continue

    print( "Tienes: " + str( edad ) )
    edad = edad + 1


lista = [ "Elemento1", "Elemento2", "Elemento3" ]

for i in lista:
    print( i )

n = 20
for i in  range( n ): # debe ser compatible int -> int, por eso no uso range en el anterior ejemplo
    print( i ) 

for i in "Cadena":
    print( i )

# ==== Funciones
def miFuncion( num1, num2 ):
    print( num1 + num2 )

miFuncion( 3, 4 )

def miFuncion1( cad, v ): # Imprime la cadena v cantidad de veces
    print( cad * v )

miFuncion1( "Amor ", 4 )

def miFuncion2( cad, v = 2, *algoMas ): # *algoMas guarda los argumentos de mas en una lista que se mandan a la funcion
    #print( cad * v )
    for i in algoMas:
        print( i * v ) 

miFuncion2( "Python", 5, "Hola", "Adios", "N", "cadenas" )

def miFuncion2( cad, v = 2, **algoMas ): # **algoMas guarda los argumentos de mas en un diccionario que se mandan a la funcion
    print( cad * v )
    print( algoMas[ "cadenaExtra" ] ) # Funciona porque se ejecuta en bloque y no por linea 

miFuncion2( "Python", 5, cadenaExtra = "Hola" ) # el indicador es cadenaExtra y el contenido es hola

def miFuncion3( num1, num2 ):
    return num1 + num2

resultadoSuma = miFuncion3( 3, 4 )
print( "Suma: ", resultadoSuma )

# ==== clase y objetos

#clase
class Auto: # Primera letra con mayusculas
    marca = ""
    modelo = 2004
    placa = ""

taxi = Auto()
print( taxi.modelo )

class Matematica:
    def suma( self ):
        self.n1 = 2
        self.n2 = 3

s = Matematica()
s.suma()
print( s.n1 + s.n2 )

class Ropa:
    def __init__( self ):
        self.marca = "Willow"
        self.talla = "M"
        self.color = "Rojo"

camisa = Ropa()
print( camisa.talla )
print( camisa.marca )

class Calculadora:
    def __init__( self, n1, n2 ):
        self.suma = n1 + n2
        self.resta = n1 - n2
        self.producto = n1 * n2
        self.division = n1 / n2

operacion = Calculadora( 10, 3 )
print( operacion.suma )

class Persona1:
    edad = 27
    nombre = "Victor"

doctor = Persona1()

print( " La edad es: ", doctor.edad )

# Constructor con metodos

class Persona:
    def __init__(self, nombre, anio ):
        self.nombre = nombre
        self.anio = anio
    
    def descripcion(self):
        return "{} tiene {}".format( self.nombre, self.anio )

    def comentario(self, frase):
        return "{} dice {}".format( self.nombre, frase )

doctor = Persona( "Jose", 26 )
print( doctor.descripcion() )
print( doctor.comentario( "Hola que tal?" ) )
