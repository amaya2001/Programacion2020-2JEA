"use strict"

    var num = parseInt( prompt( "Digite un numero: ", ) );
    for( var i = 1; i <= num; i++ ){
        if( num % i == 0){
            console.log( "Divisor: " + i );
        }
    }