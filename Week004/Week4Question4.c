#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
	srandom(time(NULL));
	int a;
	a = random() % 6;
	a++;
	printf( "You rolled a %d.\n", a );
	if( a % 2 == 0 ) {
		printf( "You win!\n" );
	} else {
		printf( "You lose.\n" );
	}


	return 0;
}
