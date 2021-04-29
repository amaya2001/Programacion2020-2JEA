"use strict"

function PorConsola( num1, num2){
    console.log("La suma de " + num1 + " y " + num2 + " es " + (num1 + num2));
    console.log("La resta de " + num1 + " y " + num2 + " es " + (num1 - num2));
    console.log("La multiplicacion de " + num1 + " y " + num2 + " es " + (num1 * num2));
    console.log("La division de " + num1 + " y " + num2 + " es " + (num1 / num2));
}

function PorPantalla( num1, num2){
    document.write("La suma de " + num1 + " y " + num2 + " es " + (num1 + num2) + "<br/>");
    document.write("La resta de " + num1 + " y " + num2 + " es " + (num1 - num2) + "<br/>");
    document.write("La multiplicacion de " + num1 + " y " + num2 + " es " + (num1 * num2) + "<br/>");
    document.write("La division de " + num1 + " y " + num2 + " es " + (num1 / num2) + "<br/>");
} 

function Calcular( num1, num2 ){
        PorConsola( num1, num2 );
        PorPantalla( num1, num2 );
}

Calcular( 3, 4 );
Calcular( 5, 3 );

