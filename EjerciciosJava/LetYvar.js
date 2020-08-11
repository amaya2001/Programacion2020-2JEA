"use strict"

    //prueba con var
    var numero = 40;
    console.log( numero );
    //numero = 40
    if( true ){
        var  numero = 50;
        console.log( numero );
        //numero = 50
    }
    console.log( numero );
    //numero = 50

    // prueba con let
    console.log("=================");

    let num = 40;
    console.log( num );
    if( true ){
        let num = 50;
        console.log( num );
    }
    console.log( num );