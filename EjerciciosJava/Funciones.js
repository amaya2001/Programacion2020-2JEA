"use strict"

function calcular( num1, num2, condicion = true ){
    if( condicion == true ){ 
        console.log( "Estoy calculando -> " + num1 * num2 );
    }else{
    console.log( "No estoy calculando nada" ); 
    }
}

calcular( 3, 4);
calcular( 5, 3, false );

