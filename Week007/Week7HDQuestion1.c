#include <stdio.h>
#include <string.h>


int main(void) {
	/* Variables */
	char input[200];
	/* [Word][Character] */
	char output[10][20];
	/* Position in for loop. */
	int c = 0;
	/* Position in word. */
	int index = 0;
	/* Current word. */
	int word = 0;


	/* Take user input, should be a sentence. */
	printf( "Type a sentence with 10 or less words, each word not exceeding 19 characters.\n" );
	fflush( stdin );
	fgets( input, 200, stdin );
	input[199] = '\n';


	for( c; input[c] != '\n' && word < 10; c++ ) {
		for( c; input[c] != ' ' && input[c] != '\0' && c < 200; c++ ) {
			if( index < 19 ) {
				output[word][index] = input[c];
			}
			index++;
		}

		/*
		if( index < 19 ) {
			output[word][index + 1] = '\n';
		} else {
			output[word][19] = '\n';
		}
		*/
		index = 0;
		if( input[c + 1] != ' ' ) { word++; }
	}


	for( word = 0; word < 10; word++ ) {
		for( c = 0; output[word][c] != '\0'; c++ ) {
			printf( "%c", output[word][c] );
		}
		printf( "\n" );
	}


	return 0;
}
