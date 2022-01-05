#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void) {
	/* Constants */


	/* Variables */
	struct Student {
		int stuID;
		char name[30];
		int mark[3];
	};

	/* I can't be bothered typing struct so I'm using typedef. */
	typedef struct Student Student;


	/* Make some fake variables. */
	Student stu0001;
	stu0001.stuID = 0001;
	strcpy( stu0001.name, "Boris Johnson" );
	stu0001.mark[0] = 100;
	stu0001.mark[1] = 50;
	stu0001.mark[2] = 0;


	/* This function calculates the average value of all of the values in an
	 * array you pass to it.
	 * I figured that an int would be accurate enough, no floats here. */
	/* !!! MAKE THIS TAKE A STRUCT INSTEAD OF THE ARRAY !!! */
	int getAverageFromArray( Student* a ) {
		int size = sizeof( a->mark ) / sizeof( *a->mark );
		int result = 0;
		int i = 0;
		for( i = 0; i < size; i++ ) {
			result = result + a->mark[i];
		}
		return result / size;
	}


	/* !!! CURRENTLY DOES NOTHING !!! */
	/* Ask which student to check details of. */
	printf( "Which student would you like to view the details of?\n" );
	char input[10];
	fflush(stdin);
	fgets(input, 10, stdin);
	printf( "%s", input );

	/* This is just an example we don't care what the user input. */
	printf( "Did you mean Boris Johnson?\n\n" );


	/* Make a pointer and grab the student info that the user wanted. */
	Student* stux;
	stux = &stu0001;

	/* Work out the student's average mark. */
	int stuxAverage;
	stuxAverage = getAverageFromArray( stux );

	/* I tried to print all of these at once but the comptuer didn't like it for
	 * some reason so they're separate now. */
	printf(	"Student Details\n" );
	printf(	"Student ID:	%d\n", stux->stuID );
	printf(	"Student Name:	%s\n", stux->name );
	printf(	"Assignment 1:	%d\n", stux->mark[0] );
	printf(	"Assignment 2:	%d\n", stux->mark[1] );
	printf(	"Assignment 3:	%d\n", stux->mark[2] );
	printf(	"Average Mark:	%d\n", stuxAverage );

	return 0;
}

