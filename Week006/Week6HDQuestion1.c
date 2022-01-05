#include <stdio.h>


int main(void) {
	/* Variables */
	char str[20];
	char searchval;
	int a, b;


	/* Take user input. */
	printf( "Type a string: " );
	fflush(stdin);
	fgets( str, 19, stdin );
	/* Set the 20th position to \n because that's the delimiter. */
	str[19] = '\n';


	/* Determine the length of the string. */
	int i = 0;
	for( i = 0; str[i] != '\n'; i++ ) {}
	printf( "The length of the string is: %d\n", i );
	

	/* Iterate through the chars in the string. */
	for( i = 0; str[i] != '\n'; i++ ) {
		/* Search for the current character. */
		searchval = str[i];
		/*printf( "Searching for: %c\n", searchval );*/
		/* Iterate through the remaining values. */
		for( a = i + 1; str[a] != '\n'; a++ ) {
			/* Check if the value matches the original we're searching for. */
			if( searchval == str[a] ) {
				/*printf( "Found an instance of %c.\n", searchval );*/
				/* Shift all of the values down one place. */
				for( b = a; str[b] != '\n'; b++ ) {
					str[b] = str[b + 1];
					/*printf( "Pos %d to pos %d.\n", b, b + 1 );*/
				}
			/* Make sure adjacent repeated characters aren't missed. */
			a--;
			}
		}
	}


	/* Determine the new end position of the string. */
	for( i = 0; str[i] != '\n'; i++ ) {}
	/* Clear all the trailing newlines. */
	for( a = i; a < 20; a++ ) { str[a] = '\0'; }

	printf( "The length of the string with non-unique characters removed is: "
			"%d\n", i );
	printf( "The string after removing duplicate characters is: %s\n", str );


	return 0;
}
