socios ={1:[ "Amanda nuñes","17/03/2009", True ], 2:[ "Barbara molina","17/03/2009", True ], 3:[ "lautaro campos","17/03/2009", True ]}
print("El club tiene: ", len( socios ),"socios" )
print("****registrar pago")
numero = int(input( "Numero de socio: " ) )
socios[ numero ][ 2 ] = True