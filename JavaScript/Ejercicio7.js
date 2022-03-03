"use strict"

    const CAP = 10

    var num = parseInt( prompt( "Digite un numero: ", ) );
    document.write( "<h1> Tabla del " + num + " : </h1>" );
    for( var i = 1; i <= CAP; i++ ){
        console.log( num + "x" + i + " = " + num * i );
        document.write( "<br>" + num + "x" + i + " = " + num * i + "</br>" );

    }