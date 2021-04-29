#include "cache.h"

Cache ** reservarMatriz( int fil, int col ){
    Cache ** cMatriz = malloc( fil * sizeof( Cache* ) );
    if( cMatriz != NULL ){
        for( int i = 0; i < fil; i++ ){
            cMatriz[ i ] = malloc( col * sizeof( Cache));
            if( cMatriz == NULL ){
                printf( "error al reservar memoria." );
            }
        }
    }else{
        printf( "error al reservar memoria." );
    }
}