#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(void) {
	/* Prime random() */
	srandom(time(NULL));

	/* Variables */
	int a1[10][4] = { 0 };
	int a2[10] = { 0 };


	/* Fill the array then work out the average. */
	int x = 0;
	int y = 0;
	for( x = 0; x < 10; x++ ) {
		/* Create random values. */
		for( y = 0; y < 4; y++ ) {
			a1[x][y] = random() % 101;
			/* Add them together to be averaged later. */
			a2[x] += a1[x][y];
		}
		/* Divide them by 4 to work out the average. */
		a2[x] /= 4;
	}


	/* Display the 1st array. */
	void display2d( int ax[10][4] ) {
		for( y = 0; y < 4; y++ ) {
			for( x = 0; x < 10; x++ ) {
				printf( "%d", ax[x][y] );
				if( ax[x][y] > 99 ) {
					printf( "  " );
				} else if ( ax[x][y] > 9 ) {
					printf( "   " );
				} else {
					printf( "    " );
				}
			}
			printf( "\n" );
		}
	}

	printf( "Array 1\n" );
	display2d( a1 );


	/* Display the 2nd array. */
	void display1d( int ax[10] ) {
		for( x = 0; x < 10; x++ ) {
			printf( "%d", ax[x] );
			if( ax[x] > 99 ) {
				printf( "  " );
			} else if ( ax[x] > 9 ) {
				printf( "   " );
			} else {
				printf( "    " );
			}
		}
		printf( "\n" );
	}

	printf( "Array 2\n" );
	display1d( a2 );


	return 0;
}

