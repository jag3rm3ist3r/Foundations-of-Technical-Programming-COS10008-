#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int inputint = 0;
	char input[20];
	int digits[5] = { 0, 0, 0, 0, 0 };


	printf( "Enter an integer that is 2-5 digits in length excluding leading "
			"zeroes, this program will add the digits together.\n" );


	fflush(stdin);
	fgets(input, 10, stdin);
	inputint = atoi(input);
	printf( "\n" );


	if( inputint > 9 && inputint < 100000 ) {
		digits[4] = inputint % 100000;
		digits[3] = inputint % 10000;
		digits[2] = inputint % 1000;
		digits[1] = inputint % 100;
		digits[0] = inputint % 10;

		digits[4] = digits[4] - digits[3];
		digits[3] = digits[3] - digits[2];
		digits[2] = digits[2] - digits[1];
		digits[1] = digits[1] - digits[0];

		digits[4] = digits[4] / 10000;
		digits[3] = digits[3] / 1000;
		digits[2] = digits[2] / 100;
		digits[1] = digits[1] / 10;


		/* Print all of the numbers.
		 * They will be in reverse order:
		 * ie. digits[0] == the very last number typed. */
		int sum = 0;
		int i = 0;
		for( i = 0; i < 5; i++ ) {
			sum = sum + digits[i];
		}
		printf( "The numbers add up to: %d\n", sum );
	} else {
		printf( "Number is not between 2 and 5 digits.\n" );
	}


	return 0;
}
