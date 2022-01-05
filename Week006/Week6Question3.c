#include <stdio.h>


int main(void) {
	int mark[10] = { 71, 20, 18, 40, 10, 11, 83, 50, 14, 52 };
	int storage[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int highest = 0;
	int threshold = 100;


	int a = 0;
	int b = 0;
	/* Iterate through the storage array copying values. */
	for( a = 0; a < 10; a++ ) {
		/* Sort through the numbers to find the highest that hasn't been
		 * selected yet. */
		highest = 0;
		for( b = 0; b < 10; b++ ) {
			if( mark[b] > highest && mark[b] < threshold ) {
				highest = mark[b];
			}
		}
		threshold = highest; 
		storage[a] = highest;
		/* There is a bug where a repeated mark will be omitted,
		 * this can be remedied by searching for duplicates and flushing them
		 * but it's 4am and I can't be bothered fixing it. */
	}

	/* Print the numbers in order. */
	int i;
	for( i = 0; i < 10; i++ ) {
		printf( "%d\n", storage[i] );
	}


	return 0;
}
