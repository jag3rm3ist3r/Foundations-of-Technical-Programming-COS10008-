#include <stdio.h>


int main(void) {
	int students[10] = {10, 12, 14, 12, 11, 12, 11, 10, 11, 12 };

	int result = 0;
	int arraysize = sizeof( students ) / sizeof( *students );
	int i = 0;
	for( i = 0; i != arraysize; i++ ) {
		result = result + students[i];
	}
	result = result / arraysize;

	printf( "The average age of the students is: %d\n", result );


	return 0;
}
