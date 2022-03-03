/* Punto 3 */

/* Definición de mascota( x, y ): X tiene una mascota de especie Y. */

/* Si Juan tiene un perro, entonces Maria tiene un gato. */
mascota( maria, gato ) :- mascota( juan, perro ).

/* Si Pedro tiene un perro, entonces tambien tiene un gato. */
mascota( pedro, gato ) :- mascota( pedro, perro ).

/* Si Juan tiene un perro y Pedro tiene un gato, entonces Laura tiene un perro. */
mascota( laura, perro ) :- mascota( juan, perro ), mascota( pedro, gato ).

/* Si Maria y Pedro tienen mascotas de la misma especie, entonces Juan tiene un gato. */
mascota( juan, gato ) :- ( mascota( maria, perro ) , mascota( pedro, perro ) ).
mascota( juan, gato ) :- ( mascota( maria, gato ), mascota( pedro, gato) ).

/* Todos los hombres tienen perros. */
mascota(pedro,perro).
mascota(juan,perro).





