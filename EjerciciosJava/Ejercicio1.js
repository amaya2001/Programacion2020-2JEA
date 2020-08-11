"use strict"

    var num1 = parseInt( prompt( "Digite un numero: ", ) );
    var num2 = parseInt( prompt( "Digite otro numero: ", ) );

    while( num1 <= 0 || num2 <= 0 || isNaN( num1 ) || isNaN( num2 ) ){
        var num1 = prompt( parseInt( "Digite un numero: ", ) );
        var num2 = prompt( parseInt( "Digite otro numero: ", ) );
    }

    if( num1 == num2 ){
        console.log( "Los numeros son iguales!" );
    }else if( num1 > num2 ){
        console.log( "El " + num1 + " es mayor que el " + num2 );
    }else{
        console.log( "El " + num1 + " es menor que el " + num2 );
    }
