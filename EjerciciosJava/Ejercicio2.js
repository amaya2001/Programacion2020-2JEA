"use strict"

    var suma = 0;
    var contador = 0;

    do{
        var numero = parseInt( prompt( "Digite un numero: ", ) );
        if( isNaN( numero ) ){
            numero = 0;
        }else if( numero >= 0 ){
            suma += numero;
            contador ++;
        }
    }while( numero >= 0 );

    console.log( "La suma de los numeros es: " +  suma );
    console.log( "La media es: " + ( suma / contador ) );
