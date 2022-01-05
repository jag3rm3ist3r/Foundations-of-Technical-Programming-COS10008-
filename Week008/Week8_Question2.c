#include <stdio.h>
#include <stdlib.h>

float calculateSum( float a, float b, float c ) {
	return a + b + c;
}

/* Take nth input. */
float inputNumber( int n ) {
	char option[10];
	if( n == 0 )		{ printf( "1st number: " ); }
	else if( n == 1 )	{ printf( "2nd number: " ); }
	else if( n == 2 )	{ printf( "3rd number: " ); }
	else				{ printf( "%dth number: ", n + 1 ); }
	fflush( stdin );
	fgets( option, 10, stdin );
	return atof( option );
}

int main() {
	float input[3];

	input[0] = inputNumber(0);
	input[1] = inputNumber(1);
	input[2] = inputNumber(2);

	/* Calculate result. */
	printf(	"The result is: %.2f\n",
			calculateSum( input[0], input[1], input[2] ) );

	return 0;
}
