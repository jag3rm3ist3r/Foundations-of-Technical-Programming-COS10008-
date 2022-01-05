#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>


int main(void) {
	srandom(time(NULL));

	int generateRandom( int min, int max ) {
		int result;
		int modulo;
		modulo = max - min + 1;
		result = random() % modulo;
		result = result + min;
		printf( "You rolled a %d!\n", result );
		return result;
	}

	/* The player rolls a 6 sided die, if they roll an even number they win. */
	int finalResult =	generateRandom( 1, 6 ) +
						generateRandom( 1, 6 ) +
						generateRandom( 1, 6 ) +
						generateRandom( 1, 6 ) +
						generateRandom( 1, 6 );
	printf( "The total is %d.\n", finalResult );
	if( finalResult % 2 == 0 && finalResult > 15 ) {
		printf( "You win!\n" );
	} else {
		printf( "You lose.\n" );
	}

	return 0;
}

