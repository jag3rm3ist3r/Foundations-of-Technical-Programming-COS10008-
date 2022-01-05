#include <stdio.h>
#include <ctype.h>


int main(void) {
	char input[20];
	char a;
	char b;
	int dist;


	/* Take input. */
	printf( "Type a letter.\n" );
	fflush(stdin);
	fgets(input, 10, stdin);
	printf( "\n" );
	a = input[0];

	printf( "Type a letter.\n" );
	fflush(stdin);
	fgets(input, 10, stdin);
	printf( "\n" );
	b = input[0];

	/* All letters will be converted to uppercase so it doesn't throw the
	 * distance off. */
	a = toupper(a);
	b = toupper(b);


	/* Check for non alphas. */
	if( isalpha(a) && isalpha(b) ) {
		printf( "The two letters you selected are %c and %c.\n", a, b );
		/* Always subtract the smaller from the larger. */
		if( a > b ) { dist = a - b; } else { dist = b - a; }
		printf( "The distance between the two characters is: %d\n", dist );
	} else {
		/* Error. */
		printf( "Please enter only letters.\n" );
	}


	return 0;
}
