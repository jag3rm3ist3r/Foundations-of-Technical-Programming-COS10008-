#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(void) {
	/* Prime random() */
	srandom(time(NULL));

	/* Variables */
	int a1[20] = { 0 };


	/* Fill the array and print it all at once. */
	int x = 0;
	int y = 0;
	for( x = 0; x < 20; x += 2 ) {
		/* Create random values. */
		a1[x] = random() % 101;
		printf( "%d ", a1[x] );
		/* Make sure the columns line up nicely. */
		if( a1[x] < 10 ) {
			printf( "  " );
		} else if ( a1[x] < 100 ) {
			printf( " " );
		}
		/* Every 2nd number is double every 1st number. */
		a1[x + 1] = a1[x] * 2;
		printf( "%d\n", a1[x + 1] );
	}


	return 0;
}

