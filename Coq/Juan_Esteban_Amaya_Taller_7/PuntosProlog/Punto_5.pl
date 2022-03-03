/* Punto 5 */

/* Maria es mujer */
mujer( maria ).

/* John es hombre */
hombre( john ).

/* John esta sano */
sano( john ).

/* Maria esta sana */
sano( maria ).

/* John es adinerado */
adinerado( john ).

/* Un viajero es todo aquel que está sano y es adinerado */
viajero( X ):- ( sano( X ), adinerado( X ) ).

/* Cualquiera puede viajar si es un viajero */
viajar( X ) :- viajero( X ).


