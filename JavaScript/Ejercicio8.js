"use strict"

    var num1 = parseInt( prompt( "Digite un numero: ", ) );
    var num2 = parseInt( prompt( "Digite otro numero: ", ) );

    while( num1 < 0 || num2 <= 0 || isNaN( num1 ) || isNaN( num2 ) ){
        num1 = parseInt( prompt( "Digite un numero: ", ) );
        num2 = parseInt( prompt( "Digite otro numero: ", ) );  
    }

    var resultado = "Suma: " + (num1 + num2 )+ "<br/>" + 
                    "Resta: " +( num1 - num2) + "<br/>" +
                    "Multiplicacion: " + (num1 * num2) + "<br/>" + 
                    "Division: " + (num1 / num2) + "<br/>";

    var resultadoCMD = "Suma: " + (num1 + num2 )+ "\n" + 
                       "Resta: " +( num1 - num2) + "\n" +
                       "Multiplicacion: " + (num1 * num2) + "\n" + 
                       "Division: " + (num1 / num2) + "\n";


    alert( resultadoCMD );
  

    console.log( resultadoCMD );

    
    document.write( "<body>" + resultado + "</body>" );

