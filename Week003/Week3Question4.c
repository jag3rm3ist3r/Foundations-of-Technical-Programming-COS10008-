#include <stdio.h>

int main(void) {
	int mark[3] = {100, 100, 59};

	if(	mark[0] >= 60 &&
		mark[1] >= 60 &&
		mark[2] >= 60 &&
		mark[0] + mark[1] + mark[2] / 3 > 65 ) {
		printf( "The student has passed.\n" );
	} else {
		printf( "The student has failed.\n" );
	}

	return 0;
}
