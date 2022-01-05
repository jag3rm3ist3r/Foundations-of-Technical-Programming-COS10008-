#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
	srandom(time(NULL));
	int a = 0;
	int roll = 0;
	int i = 0;

	int diceRoll() {
		roll = random() % 6 + 1;
		printf( "You rolled a: %d\n", roll );
		return roll;
	}

	for( i = 0; i < 5; i++ ) {
		a = a + diceRoll();
	}

	printf( "You rolled a total of %d.\n", a );

	if( a % 2 == 0 && a > 15 ) {
		printf( "You won!\n" );
	} else {
		printf( "You lose.\n" );
	}


	return 0;
}
