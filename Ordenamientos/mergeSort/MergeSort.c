#include "MergeSort.h"

void merge( int a[ ], int left_low, int left_high, int right_low, int right_high ){
	int lenght = right_high - left_low + 1;
	int temp[ lenght ];

	int left = left_low;
	int right = right_low, i;

	for( i = 0; i < lenght; ++i ){
		if( left > left_high ){
			temp[ i ] = a[ right++ ];
		}else if( right > right_high ){
			temp[ i ] = a[ left++ ];
		}else if( a[ left ] <= a[ right ] ){
			temp[ i ] = a[ left++ ];
		}else{
			temp[ i ] = a[ right++ ];
		}
	}
	for( i = 0; i < lenght; ++i ){
		a[ left_low++ ] = temp[ i ];
	}	

}

void ms( int a[ ], int low, int high ){
	if( low >= high ){
		return;
	}else{
		int mid = ( low + high ) / 2;
		ms( a, low, mid );
		ms( a, mid + 1, high );
		merge( a, low, mid, mid + 1, high );
	}
}

void merge_sort( int a[ ], int lenght ){
	ms( a, 0, lenght - 1 );
}