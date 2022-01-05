#include <stdio.h>


int main(void) {
	int sample[10] = { 13, 22, 33, 14, 5, 60, 7, 8, 9, 10 };
	int i;
	int total = 0;
	int minval = 0;
	int maxval = 0;


	for( i = 0; i < 10; i++ ) {
		total += sample[i];
		/* Testing purposes. *
		printf( "total: %d - ", total );
		printf( "sample[%d]: %d\n", i, sample[i] );
		/**/
		if( sample[i] > maxval ) { maxval = sample[i]; }
		if( sample[i] < minval ) { minval = sample[i]; }
	}


	printf( "The total was: %d\n", total );
	printf( "The minimum value was: %d\n", minval );
	printf( "The maximum value was: %d\n", maxval );
	printf( "The average value was: %d\n", total / 10 );


	return 0;
}
