# repaso diccionario

# diccionario python
nombres = { 1: "marco", 2: "juan", 3: "lola", 4: True, 5: False, 3: "carlos" }
# si hay un dato esta duplicado, solo imprime el primero de izquierda a derecha
print( nombres )

tupla = {"nombre": "marco", "edad": 25, "tup": ("marco", 2, 4, "george" )}
print( tupla )

lista = {"nombre": "marco", "edad": 25, "list": ["marco", 2, 4, "george" ]}
print( lista )

# tamaño
print( len( nombres ) )
print( len( tupla ) )
# acceder a elementos keys(), values(), items() ->

print( nombres[2] )
x = nombres[ 2 ]
print( x )

# keys -> las llaves asociadas al diccionario
print( nombres.keys() )
# values -> los valores asociados al diccionario
print( nombres.values() )
# items -> almacena al diccionario en una lista de tuplas 
print( nombres.items() )

# cambiar un elemento ->
nombres[ 3 ] = "carla"
print( nombres )

nombres.update({3: "isa"})
print( nombres )

# agregar un elemento ->
nombres.update({7: "lola"})
print( nombres )

# eliminar un elemento ->
nombres.pop( 3 )
print( nombres )
nombres.popitem() # elimina el ultimo valor
print( nombres )
del nombres[ 2 ]
print( nombres )
nombres.clear() # elimina todo el diccionario
print( nombres )

print("===============================================S")

contadores = {}
cadena = input("cadena de caracteres: ")
for caracter in cadena:
    if caracter not in contadores.keys(): 
        contadores[ caracter ] = 1
    else:
        contadores[ caracter ] += 1

for llave, cantidad in contadores.items():
    print( llave,":", cantidad )
