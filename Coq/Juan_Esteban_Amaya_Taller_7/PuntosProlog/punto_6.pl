rightTo(X, Y) :- X is Y+1.
leftTo(X, Y) :- rightTo(Y, X).
nextTo(X, Y) :- rightTo(X, Y).
nextTo(X, Y) :- leftTo(X, Y).
riddle(Houses, FishOwner) :-
    Houses = [
        house(1, _, _, _, _, _),
        house(2, _, _, _, _, _),
        house(3, _, _, _, _, _),
        house(4, _, _, _, _, _),
        house(5, _, _, _, _, _)
    ],

    /* 1. El britanico vive en la casa roja. */
    member(house(_,britanico,roja,_,_,_), Houses),
    /* 2. El sueco tiene un perro. */
    member(house(_,suizo,_,perro,_,_), Houses),
    /* 3. El danes toma te. */
    member(house(_,danes,_,_,te,_), Houses),

    /* 4. La casa verde esta a la izquierda de la blanca. */
    member(house(A,_,verde,_,_,_), Houses),
    member(house(B,_,blanco,_,_,_), Houses),
    leftTo(A, B),

    /* 5. El due˜no de la casa vede toma cfe. */
    member(house(_,_,verde,_,cafe,_), Houses),
    /* 6. La persona que fuma Pall Mall tiene un pajaro. */
    member(house(_,_,_,pajaro,_,pallMall), Houses),
    /* 7. El due˜no de la casa amarilla fuma Dunhi. */
    member(house(_,_,amarillo,_,_,dunhill), Houses),
    /* 8. El que vive en la casa del centro toma leche. */
    member(house(3,_,_,_,leche,_), Houses),
    /* 9. El noruego vive en la primera casa. */
    member(house(1, noruego,_,_,_,_), Houses),

    /* 10. La persona que fuma Brends vive junto a la que tiene un gato. */
    member(house(C,_,_,_,_,brends), Houses),
    member(house(D,_,_,gato,_,_), Houses),
    nextTo(C, D),

    /* 11. La persona que tiene un caballo vive junto a la que fuma Dunhill. */
    member(house(E,_,_,caballo,_,_), Houses),
    member(house(F,_,_,_,_,dunhill),Houses),
    nextTo(E, F),

    /* 12. El que fuma Bluemasters bebe cerveza. */
    member(house(_,_,_,_,cerveza, bluemasters), Houses),
    /* 13. El aleman fuma prince. */
    member(house(_,aleman,_,_,_,prince), Houses),

    /* 14. El noruego vive junto a la casa azul. */
    member(house(G,noruego,_,_,_,_), Houses),
    member(house(H,_,azul,_,_,_), Houses),
    nextTo(G, H),

    /* 15. El que fuma Brends tiene un vecino que toma agua. */
    member(house(I,_,_,_,_,brends), Houses),
    member(house(J,_,_,_,agua,_), Houses),
    nextTo(I, J),

    member(house(_,FishOwner,_,fish,_,_), Houses).














