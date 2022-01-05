#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(void) {
	srandom(time(NULL));

	typedef int twodArray[5][2];
	twodArray a1, a2, a3;

	int x = 0;
	int y = 0;
	for( y = 0; y < 2; y++ ) {
		for( x = 0; x < 5; x++ ) {
			a1[x][y] = random() % 101;
			a2[x][y] = random() % 101;
			a3[x][y] = a1[x][y] + a2[x][y];
		}
	}

	void display( twodArray ax ) {
		for( y = 0; y < 2; y++ ) {
			for( x = 0; x < 5; x++ ) {
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
	display( a1 );

	printf( "Array 2\n" );
	display( a2 );

	printf( "Array 3\n" );
	display( a3 );

	return 0;
}

