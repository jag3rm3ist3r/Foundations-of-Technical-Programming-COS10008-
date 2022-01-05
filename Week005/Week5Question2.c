#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int inputint = 0;
	char input[20];


	printf( "Pick an odd number.\n" );
	fflush(stdin);
	fgets(input, 10, stdin);
	inputint = atoi(input);
	printf( "\n" );


	int a = 0;
	int b = 0;
	int c = 0;
	int quantity = 0;
	if( inputint % 2 == 1 ) {
		/* Find the midpoint. */
		quantity = ( inputint - 1 ) / 2;
		for( a = 0; a < inputint; a++ ) {
			/* Work out how many asterisks we need to print on this line. */
			if( c <= quantity && a <= quantity ) {
				c++;
			} else {
				c--;
			}

			for( b = 0; b < c; b++ ) {
				printf( "* " );
			}

			/* Print the newline character separately. */
			printf( "\n" );
		}
	} else {
		printf( "That is not an odd number.\n" );
	}
	printf( "\n" );


	return 0;
}
