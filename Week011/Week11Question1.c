#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	int option=0, j=0, k=0, delete=0, position=0;
 	// keeps the count of numbers added
	int count=0;
	typedef struct studentStruct {
		char name[10];
		int id;
		char address[100];
	} studentStruct;
	studentStruct *p = NULL;
	printf("~~~~~Student Info Storage~~~~~\n");
	bool showMenu() {
		bool retval = true;
		printf("1- Add new Number\n");
		printf("2- List student id(s)\n");
		printf("3- Delete a student\n");
		printf("4- Quit\n");

		scanf("%d",&option);
		
		switch (option) {
			case 1:
				count++;
				//using realloc memory is requested for the new number
				p = realloc(p, sizeof(studentStruct) * (count));

				printf("Your number (1 or above) : ");
				fflush(stdin);
				scanf("%d", &p[count - 1].id);

				printf("Your name : ");
				fflush(stdin);
				scanf("%s", &p[count - 1].name);

				printf("Your address : ");
				fflush(stdin);
				scanf("%s", &p[count - 1].address);

				printf("\n");
				break;
			
			case 2: printf("~~~~~Your Numbers(s)~~~~~\n");
				for(j=0; j<count; j++) {
					if(p[j].id != 0) {printf("~%d", p[j].id);}
				}
				printf("~\n");
				break;
			
			case 3: k=count;
				printf("Choose what you want to delete...");
				scanf("%d", &delete);
				// Loop so search for the number to be deleted.
				for(j=k; j>=0; j--) {
					// Number is found.
					if(delete == p[j].id) {
						printf("Deletion successful ...\n");
						// A value of 0 indicates the value is deleted.
						p[j].id = 0;
						// I refuse to zero the other values because I'm lazy.
					} else {
						printf("Number not in the list ...\n");
					}
				}
				
				printf("\n");
				break;
			
			case 4:
				retval = false;
				break;
		}
		return retval;
	}

	while(showMenu()) {};

	return 0;
}
