/* Input output */
#include <stdio.h>
/* atoi */
#include <stdlib.h>
/* true/false statements */
#include <stdbool.h>
/* gdb debugging */
#include <signal.h>
/* string handling, might not need this. */
#include <string.h>



int main(void) {
	int ticketCost = 15;
	/*int seats[10][8] =	{0};
	/**/
	/* Define custom initial array. (testing purposes only) */
	int seats[10][8] =	{
							{1, 0, 1, 0, 0, 1, 0, 0},
							{0, 1, 0, 1, 0, 1, 0, 1},
							{1, 0, 1, 0, 0, 0, 1, 0},
							{0, 1, 0, 1, 0, 1, 0, 1},
							{0, 0, 1, 0, 0, 1, 0, 0},
							{1, 0, 0, 1, 0, 0, 1, 0},
							{1, 0, 0, 1, 0, 0, 1, 0},
							{1, 0, 0, 1, 0, 0, 1, 0},
							{1, 0, 0, 1, 0, 0, 1, 0},
							{1, 0, 0, 1, 0, 0, 1, 0}
						};
	/**/

	/* Clear junk out of stdin to stop it causing problems reading input. */
	void clearstdin(void) {
		/* Clear junk out of stdin. *
		int c;
		while ((c = getchar()) != '\n' && c != EOF) { }
		/**/
		fflush(stdin);
	}

	/* Print a map of the available seats */
	void currentAvailability( int xstart, int ystart, int ammount ) {
		int x = 0;
		int y = 0;
		char aisleLetter;
		printf("   1  2  3  4  5  6  7  8  9 10\n");
		for ( y; y < 8; y++ ) {
			/* This will convert the aisle number to a letter. */
			aisleLetter = y + 'A';
			printf("%c  ", aisleLetter);
			for ( x; x < 10 ; x++ ) {
				if (ammount != 0 &&
					x >= xstart &&
					x <= xstart + ammount - 1 &&
					y == ystart ) {
					printf("?  ");
				} else {
					if ( seats[x][y] == 0 ) {
						printf(".  ");
					} else {
						printf("R  ");
					}
				}
			}
			printf("\n");
			x = 0;
		}
	}

	/* Print the number of available seats left */
	int availableSeats(void) {
		int freeCount = 0;
		int x = 0;
		int y = 0;
		for ( y; y < 8; y++ ) {
			for ( x; x < 10; x++ ) {
				if ( seats[x][y] == 0 ) {freeCount++;}
			}
			x = 0;
		}
		return freeCount;
	}

	/* Reserve available seats */
	/* This function will actually accept more than 10 seats at a time,
	 * the restriction for 10 or less seats is placed on the function call. */
	void reserveTickets(int orderSize, int row , int seatno) {
		int x = 0;
		int indexSeatX = 0;
		int tailSeatX = 0;
		int y = 0;
		int indexSeatY = 0;
		int tailSeatY = 0;
		int contiguousSeats = 0;



		/* Reserve a group of seats in a row. *
		void markReservation( int xstart, int ystart, int reservation) {
			/* Reset and reuse x and y for iterating through the seats because I
			 * can't be bothered typing "start". *
			x = xstart;
			y = ystart;
			int reserved = 0;
			/* Iterate through the seats and mark the correct ammount as
			 * reserved. *
			for ( y; y < 8 && reservation != reserved; y++ ) {
				for ( x; x < 10 && reservation != reserved; x++) {
					seats[x][y] = 1;
					/* Testing purposes only. *
					printf("Checking seats: x%d y%d\n", x, y);
					/**
					reserved++;
					/* Testing purposes only. *
					printf("%d\n", reserved);
					/**
				}
				x = 0;
			}
		}
		*/

		/* Allocate seats given that they're not taken. */
		void markReservation( int xstart, int ystart, int reservation ) {
			/* Reset and reuse x and y for iterating through the seats because I
			 * can't be bothered typing "start". */
			x = xstart;
			y = ystart;
			int reserved = 0;
			/* Iterate through the seats and mark the correct ammount as
			 * reserved. */
			for ( y; y < 8 && reservation != reserved; y++ ) {
				for ( x; x < 10 && reservation != reserved; x++) {
					/* Testing purposes only. *
					printf("Checking seats: x%d y%d\n", x, y);
					/**/
					if ( seats[x][y] == 0 ) {
						seats[x][y] = 1;
						char sletter = y + 'A';
						char snumber = x + 'A';
						printf(	"You have been placed into seat %c%d.\n",
								sletter, snumber );
						reserved++;
						/* Testing purposes only. *
						printf("%d\n", reserved);
						/**/
					}
				}
				x = 0;
			}
		}


		/* For testing purposes only. *
		printf("Running reserve tickets function now.\n");
		/**/

		/* Testing purposes only. *
		printf("row:%d\n", row);
		printf("seatno:%d\n", seatno);
		/**/

		/* Only set the row if the user specified something,
		 * otherwise just start at the start.
		 * This has to check if it's already zero so we don't start at -1. */
		if ( row != 0 ) { y = row - 1; }
		if ( seatno != 0 ) { x = seatno - 1; }


		/* Testing purposes only. *
		printf("x:%d\n", x);
		printf("y:%d\n", y);
		/**/

		/* Testing purposes only. *
		printf("orderSize:%d\n", orderSize);
		printf("contiguousSeats:%d\n\n", contiguousSeats);
		/**/

		for (	y;
				y < 8 && contiguousSeats != orderSize;
				y++ ) {
			/* Restrict the allocation to one row so we don't spill across to
			 * the next row. */
			contiguousSeats = 0;
			/* Move through the columns (across the aisle) starting with 0
			 * (seat 1) */
			for (	x;
					x < 10 && contiguousSeats != orderSize;
					x++ ) {
				/* Testing purposes only. *
				printf("Checking seats: x%d y%d\n", x, y);
				/**/
				/* For testing purposes only *
				printf("Reserved: %d\n\n", seats[x][y]);
				/**/
				if ( seats[x][y] == 0 ) {
					/* Set the starting position of the chain of empty
					 * seats if this is the first one we have found. */
					if ( contiguousSeats == 0 ) {
						indexSeatX = x;
						indexSeatY = y;
					}
					/* The seat is empty so we count it and move on. */
					contiguousSeats = contiguousSeats + 1;
					/* For testing purposes only. *
					printf("Contiguous seats: %d\n\n", contiguousSeats);
					/**/
					/* Make sure we track where the chain of empty seats ends. */
					if ( contiguousSeats == orderSize ) {
						tailSeatX = x;
						tailSeatY = y;
					}
				} else {
					contiguousSeats = 0;
				}
			}
			/* Start at the start of the next row. */
			x = 0;
		}

		/* For testing purposes only. *
		printf(	"Head:x%dy%d\n"
				"Tail:x%dy%d\n",
				indexSeatX,
				indexSeatY,
				tailSeatX,
				tailSeatY);
		/**/

		/* Increment the ASCII value by A (41) in order to make aisle letters
		 * out of the aisle number. */
		char indexSeatLetter;
		indexSeatLetter = indexSeatY + 'A';
		char tailSeatLetter;
		tailSeatLetter = tailSeatY + 'A';

		/* For testing purposes only. *
		printf("indexSeatLetter:%c\n", indexSeatLetter);
		printf("tailSeatLetter:%c\n", tailSeatLetter);
		/**/

		/* We have found a group of seats or there is no group of seats
		 * large enough to accomodate the order. */
		char yesno[10];
		if ( contiguousSeats == orderSize ) {
			/* Place order successfuly. */
			int price = ticketCost * orderSize;
			printf("Seats %c%d through %c%d are free, would you like to "
					"reserve them?\n"
					"The price will be $%d.\n\n",
					indexSeatLetter,
					indexSeatX + 1,
					tailSeatLetter,
					tailSeatX + 1,
					price);

			currentAvailability( indexSeatX, indexSeatY, orderSize );

			/* Take input. */
			clearstdin();
			fgets(yesno, 8, stdin);

			/* Handle the user deciding where to be seated. */
			if ( strncmp(yesno, "y", 1) == 0 ) {
				printf("Seats reserved.\n");
				markReservation(indexSeatX, indexSeatY, orderSize);
			} else {
				printf("Seat reservation cancelled.");
			}
		} else {
			/* Can't find enough contiguous seats.
			 * Ask if they want to get dumped anywhere. */
			printf(	"Not enough seats in one row to satisfy request.\n"
					"Would you like to be placed into the remaining available "
					"seats?\n");
			clearstdin();
			fgets(yesno, 8, stdin);

			/* Handle the user deciding where to be seated. */
			if ( strncmp(yesno, "y", 1) == 0 ) {
				markReservation( 0, 0, orderSize );
			}
		}
	}


	/* Ask the user how they would like their seats selected. */
	void reservationInput(void) {
		printf("Reserve tickets:\n");
		/* Variables */
		int selection;
		int seatAmmount = 0;
		int seatRow = 0;
		int seatNumber = 0;
		/* Used to store strings the user inputs. */
		unsigned char selectionChar[10] = {'a'};

		/* Debugging interupt. *
		raise(SIGINT);
		/**/

		/* How many? */
		printf("How many seats would you like to reserve? ");
		/*scanf("%d [1-10]", &selection);*/
		/*clearstdin();*/
		fgets(selectionChar, 10, stdin);
		seatAmmount = atoi(selectionChar);

		/* For testing purposes only. *
		printf("%d\n", seatAmmount);
		/**/

		/* Is the machine deciding where they are for you? Y/N */
		printf("Would you like the computer to allocate seats for "
				"you? (y/n) ");
		/*scanf("%c", &selectionChar);*/
		clearstdin();
		fgets(selectionChar, 10, stdin);

		/* Handle the user deciding where to be seated. */
		if ( strncmp(selectionChar, "n", 1) == 0 ) {
			printf("What row & seat would you like to reserve the "
					"seats from?\n"
					"Row (A-H): ");
			/*scanf("%c [a-h]", &selectionChar[1]);*/
			clearstdin();
			fgets(selectionChar, 10, stdin);

			/* Testing purposes only. *
			printf("selectionChar[1]:%d\n", selectionChar[1]);
			printf("(int)selectionChar[1]:%d\n", (int)selectionChar[1]);
			/**/

			/* Subtract the ascii value for "a" to create a useful number.
			 * I'm assuming the input is lowercase but I could convert the
			 * string to all uppers then assume uppercase to avoid issues. */
			seatRow = selectionChar[0] - 'a' + 1;

			/* Testing purposes only. *
			printf("%d\n", seatRow);
			/**/

			/* Ask about seat number. */
			printf("Seat number (1-10): ");
			/*scanf("%d [1-10]", &seatNumber);*/
			clearstdin();
			fgets(selectionChar, 10, stdin);
			seatNumber = atoi(selectionChar);
			/* For testing purposes only. *
			printf("%d", seatNumber);
			/**/
		}

		/* For testing purposes only. *
		printf("%d\n", seatAmmount);
		/**/
		/* Only accept orders of 10 or less tickets at a time. */
		if ( seatAmmount > 10 ) {
			/* Invalid order size that is greater than 10. */
			printf("Sorry, a maximum of 10 tickets can be reserved "
					"at one time.");
		} else if ( seatAmmount > availableSeats() ) {
			/* Not enough seats left. */
			printf(	"Sorry, you have requested more seats than the remaining "
					"quantity, there are only %d seats available.",
					availableSeats() );
		} else {
			/* Reserve the tickets. */
			reserveTickets(seatAmmount, seatRow, seatNumber);
			/**/
		}
	}


	/* Make a bool to decide whether to continue looping the menu or quit. */
	bool cont = true;

	int menu(void) {
		/* Main menu text */
		printf("\n\nCinema Ticketing System\n\n"
				"1 - Reserve Tickets\n"
				"2 - Show Current Availability\n"
				"3 - Count Available Seats\n"
				"4 - Exit\n"
				"Enter your choice...\n\n");

		/* Handle menu selection */
		/*clearstdin();*/
		char option[10];
		/*scanf("%d", &option);*/
		/*clearstdin();*/
		fgets(option, 10, stdin);
		int optionInt = atoi(option);
		printf("\n");

		/* For testing purposes only. *
		printf("%d\n", test);
		/**/

		switch (optionInt) {
			case 1: reservationInput();
					break;
			case 2:	printf("Current availability:\n");
					currentAvailability(0, 0, 0);
					break;
			case 3: printf("Available seat count:\n"
							"%d", availableSeats());
					break;
			default:printf("Exiting...\n\n");
					cont = false;
					break;
		}
	}

	while ( cont == true ) {
		menu();
	}
	return 0;
}
