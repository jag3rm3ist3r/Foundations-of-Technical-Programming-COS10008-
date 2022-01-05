#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(void) {
	/* Variables */
	int a = 0;
	int b = 1;
	

	printf( "How many fib numbers do you need?\n" );
	char input[20];
	fflush(stdin);
	fgets(input, 10, stdin);
	int limit = atoi(input);


	printf( "\n" );


	if( limit < 1 ) {
		printf( "Limit can't be less than one." );
		limit = 0;
	}


	int speedms = 500000;
	int i = 0;
	for( i = 0; i != limit; i++ ) {
		/* Add to alternating variables to keep the previous result intact. */
		printf( "%d : ", i + 1 );
		if( i % 2 == 0 ) {
			printf( "%d\n", a );
			a = a + b;
			usleep(speedms);
		} else {
			printf( "%d\n", b );
			b = a + b;
			usleep(speedms);
		}
	}


	printf( "\n" );

	
	return 0;
}
