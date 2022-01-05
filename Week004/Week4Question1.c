#include <stdio.h>

int main(void) {
	/* Variables */
	int mark[3] = { 80, 80, 80 };
	int averageMark = 0;


	/* Calculate the average. */
	averageMark = mark[0] + mark[1] + mark[2];
	averageMark = averageMark / 3;

	/* Check if the student passed. */
	if(	mark[0] >= 60 &&
		mark[1] >= 60 &&
		mark[2] >= 60 &&
		averageMark > 65 ) {
		printf( "The student has passed.\n" );
	} else {
		printf( "The student has failed.\n" );
	}


	return 0;
}
