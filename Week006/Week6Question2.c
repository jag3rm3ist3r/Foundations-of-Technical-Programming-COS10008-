#include <stdio.h>
#include <stdlib.h>


int main(void) {
	char str[80];
	int ccount = 0;


	int countchars(void) {
		int i;
		for( i = 0; str[i] != '\n'; i++ ) {}
		return i;
	}


	int searchchars( char param ) {
		int i;
		int ret = 0;
		for(i = 0; str[i] != '\n'; i++ ) {
			if( str[i] == param ) {
				ret++;
			}
		}
		return ret;
	}


	printf( "Please enter a string: " );
	fflush( stdin );
	fgets( str, 80, stdin );
	printf( "This is the string you typed:\n%s\n", str );
	ccount = countchars();
	printf( "The string contains %d characters.\n", ccount );

	printf( "Enter a letter to search for: " );
	fflush( stdin );
	char searchfor[100];
	fgets( searchfor, 80, stdin );
	printf( "The letter appeared %d time/s in the string.\n",
			searchchars( searchfor[0] ) );


	return 0;
}
