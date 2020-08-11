"use strict"

    var num1 = parseInt( prompt( "Digite un numero: ", ) );
    var num2 = parseInt( prompt( "Digite un numero: ", ) );

    if( num1 > num2 ){
        document.write( "<h1> Los numeros impares entre el " + num2 + " y el " + num1 + " son: </h1>" );
        for( var i = num2 + 1; i < num1; i++ ){
            if( i % 2 != 0){
                document.write( i + "<br/>" );
            }    
        }
    }else if( num2 > num1 ){
        document.write( "<h1> Los numeros impares entre el " + num1 + " y el " + num2 + " son: </h1>" );
        for( var i = num1 + 1; i < num2; i++ ){
            if( i % 2 != 0){
                document.write( i + "<br/>" );
            }   
        }
    }else{
        document.write( "<h1> Los numeros son iguales. </h1>" );
    }
    