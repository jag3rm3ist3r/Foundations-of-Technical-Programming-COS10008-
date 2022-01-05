#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>


int main(void) {
	srandom(time(NULL));

	/* Variables */
	int r1 = random() % 5;
	int r2 = random() % 5;


	/* This is needed to maintain the loop till the user opts out. */
	bool cont = true;
	/* This is the main game loop. */
	void gameLoop(void) {
		/* Variables */
		int answer = 0;

		/* Create two new numbers. */
		r1 = random() % 10;
		r2 = random() % 10;

		printf("Add the following numbers.\n\n");

		while ( answer != r1 + r2 ) {
			/* Ask the user what the answer is. */
			printf("How much is %d + %d? Enter -1 to quit. ", r1, r2);
			scanf("%d", &answer);
			printf("\n");
	
			/* Handle user response. */
			int rresp = random() % 4 + 1;
			if ( answer == -1 ) {
				/* Quit out of the main game loop. */
				cont = false;
				/* Make the answer correct so that the user doesn't get asked
				 * again when they're trying to leave the game. */
				answer = r1 + r2;
				printf("Exiting.\n\n");
			} else {
				/* Handle responses. */
				if ( answer == r1 + r2 ) {
					switch ( rresp ) {
					case 1:	printf("Very good!");
							break;
					case 2:	printf("Excellent!");
							break;
					case 3:	printf("Nice work!");
							break;
					case 4:	printf("Keep up the good work!");
							break;
					}
				} else {
					switch ( rresp ) {
					case 1:	printf("No. Please try again.");
							break;
					case 2:	printf("Wrong. Try once more.");
							break;
					case 3:	printf("Don't give up!");
							break;
					case 4:	printf("No. Keep trying.");
							break;
					}
				}
			}
			/* Keeps the questions spaced out nicely and stops the terminal
			 * prompt from starting on the same line when you choose to quit. */
			printf("\n\n");
		}
	}

	while ( cont == true ) {
		gameLoop();
	}

	return 0;
}

