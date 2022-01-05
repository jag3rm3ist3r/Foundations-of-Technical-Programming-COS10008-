#include <stdio.h>


int main(void) {
	int a = 4;
	int b = 9;
	int c = 0;

	printf( "The two numbers are %d and %d\n", a, b );

	printf( "The sum of the numbers is: %d: \n", a + b );

	if( a > b ) { c = a - b; } else { c = b - a; }
	printf( "The difference between the numbers is: %d\n", c );

	printf( "The product of the two numbers is: %d\n", a * b );

	printf( "%d divided by %d is: %d\n", a, b, a / b );
	printf( "%d divided by %d is: %d\n", b, a, b / a );

	if( a % 2 == 0 ) {
		printf( "%d is even.\n", a );
	} else {
		printf( "%d is odd.\n", a );
	}

	if( b % 2 == 0 ) {
		printf( "%d is even.\n", b );
	} else {
		printf( "%d is odd.\n", b );
	}

	if( a > b ) { c = a; } else { c = b; }
	printf( "The biggest number between %d and %d is: %d\n", a, b, c );


	return 0;
}

