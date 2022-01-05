#include <stdio.h>
#include <stdlib.h>

int calculateSum( float a, float b, float c ) {
	printf(	"The result is: %.2f\n", a + b + c );
	return 0;
}

int main() {
	float input[2];
	char option[10];

	/* Take 1st input. */
	printf( "1st number: " );
	fflush( stdin );
	fgets( option, 10, stdin );
	input[0] = atof( option );

	/* Take 2nd input. */
	printf( "2nd number: " );
	fflush( stdin );
	fgets( option, 10, stdin );
	input[1] = atof( option );

	/* Take 2nd input. */
	printf( "3rd number: " );
	fflush( stdin );
	fgets( option, 10, stdin );
	input[2] = atof( option );

	/* Calculate result. */
	calculateSum( input[0], input[1], input[2] );

	return 0;
}
