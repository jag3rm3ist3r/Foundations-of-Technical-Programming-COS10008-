#include <stdio.h>
#include <stdbool.h>

/* Main function */
int main(void) {
	/* Constants */
	/* Pricing */
	const int babyPrice = 0;
	/* Class A */
	const int classATicketPriceFull = 25;
	const int classATicketPriceConc = 15;

	/* Class B */
	const int classBTicketPriceFull = 15;
	const int classBTicketPriceConc = 10;

	/* Class C */
	const int classCTicketPriceFull = 9;
	const int classCTicketPriceConc = 5;

	/* Array to store all pricing. */
	/* First [] bracket is class, seccond is for concession status. */
	const int ticketPricing[3][2] = {
		{classATicketPriceFull, classATicketPriceConc},
		{classBTicketPriceFull, classBTicketPriceConc},
		{classCTicketPriceFull, classBTicketPriceConc}
	};
	
	/* Children */
	const int babyAgeThreshold=3;
	const int childAgeThreshold=12;

	/* Initial ticket availability */
	const int classATickets=15;
	const int classBTickets=60;
	const int classCTickets=90;



	/* Variables */
	/* Array for all tickets. */
	int tickets[3] = {classATickets, classBTickets, classCTickets};


		
	/* Functions */
	/* Check how many tickets there are left. */
	void currentAvailability(void) {
		printf("Current Availability:\n"
				"Class A: %d\n"
				"Class B: %d\n"
				"Class C: %d\n"
				"\n\n", tickets[0], tickets[1], tickets[2]);
	}

	/* Check types of tickets. */
	void buyTickets(int ticketClass) {
		/* Arguments */
		/* int ticketClass : Used for determining which class of ticket the user
		 * has selected in the previous menu. */

		/* Constants */

		/* Variables */
		int userInput = 0;
		int fullTickets = 0;
		int concTickets = 0;
		int babyTickets = 0;
		int orderTicketCount = 0;
		int ticketPriceTotal = 0;


		/* Testing purposes only: *
		printf(
				"Class A tickets left: %d\n"
				"Class B tickets left: %d\n"
				"Class C tickets left: %d\n",
				tickets[0],
				tickets[1],
				tickets[2]);
		/**/


		/* Ask about full fare tickets. */
		printf("How many full fare tickets? ");
		scanf("%d",&userInput);

		orderTicketCount = orderTicketCount + userInput;
		fullTickets = userInput;
		ticketPriceTotal = userInput * ticketPricing[ticketClass][0];


		/* Ask about concession tickets. */
		printf("How many concession tickets? "
				"(Seniors and children over %d and under %d.) ",
				babyAgeThreshold, childAgeThreshold);
		scanf("%d",&userInput);

		orderTicketCount = orderTicketCount + userInput;
		concTickets = userInput;
		ticketPriceTotal = ticketPriceTotal +
							userInput * ticketPricing[ticketClass][1];


		/* Ask about child tickets. */
		printf("How many children under the age of %d? ", babyAgeThreshold);
		scanf("%d",&userInput);
		printf("\n");

		orderTicketCount = orderTicketCount + userInput;
		babyTickets = userInput;


		/* Testing purposes only *
		printf("orderTicketCount == %d\n"
				"tickets[ticketClass] == %d\n",
				orderTicketCount,
				tickets[ticketClass] );
		/**/


		/* Check if the customer has tried to order more tickets than are
		 * available. */
		if ( orderTicketCount <= tickets[ticketClass] ) {
			printf("You have ordered %d full cost ticket(s), "
				"%d concession/child ticket(s) and %d baby tickets.\n",
				fullTickets, concTickets, babyTickets);
			printf("Total ticket price comes to: $%d\n", ticketPriceTotal);
			tickets[ticketClass] = tickets[ticketClass] - orderTicketCount;
		} else {
			/* We'll tell the user how many tickets are left here just so they
			 * don't have to go and check for themselves. */
			printf("Tickets ordered exceed number of available tickets.\n");
			currentAvailability();
		}
	}

	bool contloop = true;
	while ( contloop == true ) {
		/* Body */
		/* Main menu text */
		printf("\n\nTrain Ticketing System\n\n"
				"1 - Class A\n"
				"2 - Class B\n"
				"3 - Class C\n"
				"4 - Current Availability\n"
				"5 - Exit\n"
				"Enter your option...\n\n");
		
	
		/* Handle menu selection */
		int option = 0;
		scanf("%d", &option);
		printf("\n");
		switch (option) {
			case 1:	printf("Class A\n");
					buyTickets(0);
					break;
			case 2:	printf("Class B\n");
					buyTickets(1);
					break;
			case 3: printf("Class C\n");
					buyTickets(2);
					break;
			case 4:	currentAvailability();
					break;
			default:printf("Exiting...\n\n");
					contloop = false;
					break;
		}
	}

	/* I have put a newline here so that my command prompt doens't get spat out
	 * on the end of the last line of text. */
	printf("\n\n");
	return 0;
}

