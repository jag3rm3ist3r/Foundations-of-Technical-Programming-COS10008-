#include <stdio.h>
#include <stdlib.h>


int sumArray( int a[], int size ) {
	int i;
	int result = 0;
	for( i = 0; i < size; i++ ) {
		result = result + a[i];
	}
	return result;
}


int main() {
	int array[5] = {64, 23, 65, 41, 65};

	printf( "%d\n", sumArray( array, sizeof( array ) / sizeof( *array ) ) );

	return 0;
}
