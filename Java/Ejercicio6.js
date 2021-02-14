"use strict"

    var num = parseInt( prompt( "Digite un numero: ", ) );
    while( isNaN( num ) ){
        num = parseInt( prompt( "Digite un numero: ", ) );
    }
    if( num % 2 == 0 ){
        console.log( "El numero " + num + " es par." );
    }else{
        console.log( "El numero " + num + " es impar." );
    }