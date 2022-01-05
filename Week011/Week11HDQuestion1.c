#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int main() {
	int option=0, j=0, delete=0, position=0;
 	// keeps the count of numbers added
	int count=0;

	typedef struct subjectStruct {
		int subjectID;
		char subjectName[10];
		float marks;
	} subjectStruct;

	typedef struct studentStruct {
		char name[10];
		int id;
		size_t enrol_len;
		subjectStruct * enrol;
	} studentStruct;
	studentStruct *p = NULL;

	bool showMenu() {
		bool retval = true;

		printf("~~~~~Student Info Storage~~~~~\n");
		printf("1- Add new student\n");
		printf("2- List student id(s)\n");
		printf("3- Delete a student\n");
		printf("4- Quit\n");

		char temp[10];
		fgets(temp, 10, stdin);
		option = atoi(temp);

		switch (option) {
			case 1:
				count++;
				//using realloc memory is requested for the new number
				p = realloc(p, count * sizeof(studentStruct));

				printf("Your number (1 or above) : ");
				p[count - 1].id = 0;
				fflush(stdin);
				fgets(temp, 10, stdin);
				p[count - 1].id = atoi(temp);

				printf("Your name : ");
				strcpy(p[count - 1].name, "");
				fflush(stdin);
				fgets(temp, 10, stdin);
				strcpy(p[count - 1].name, temp);

				printf("How many subjects will you be enroled in? (max 4) ");
				p[count - 1].enrol_len = 0;
				fflush(stdin);
				fgets(temp, 10, stdin);
				p[count - 1].enrol_len = atoi(temp);

				// Set enrol len to a max of 4.
				if(p[count - 1].enrol_len > 4) {
					printf("Maximum of 4.\n");
					p[count - 1].enrol_len = 4;
				}
				// Set enrol len to min of 0.
				if(p[count - 1].enrol_len < 0) {
					printf("Can't enrol into a negative number of subjects.");
					p[count - 1].enrol_len = 0;
				}

				// Allocate the memory.
				p[count - 1].enrol = malloc(
					p[count - 1].enrol_len * sizeof(subjectStruct)
				);

				for(int i = 0; i < p[count - 1].enrol_len; i++) {
					printf("What is the subject ID for subject #%d : ", i + 1);
					p[count - 1].enrol[i].subjectID = 0;
					fflush(stdin);
					fgets(temp, 10, stdin);
					p[count - 1].enrol[i].subjectID = atoi(temp);

					printf("What is the subject name? ");
					strcpy(p[count - 1].enrol[i].subjectName, "");
					fflush(stdin);
					fgets(temp, 10, stdin);
					strcpy(p[count - 1].enrol[i].subjectName, temp);

					printf("What is the mark for this subject? ");
					p[count - 1].enrol[i].marks = 0.00;
					fflush(stdin);
					fgets(temp, 10, stdin);
					p[count - 1].enrol[i].marks = atoi(temp);
				}

				printf("\n");
				break;
			
			case 2: printf("~~~~~Your Numbers(s)~~~~~\n");
				for(j=0; j<count; j++) {
					if(p[j].id != 0) {
						printf("Student number: %d\n", p[j].id);
						printf("Student name: %s\n", p[j].name);
						for(int i = 0; i < p[j].enrol_len; i++) {
							printf("%d\n", p[j].enrol[i].subjectID);
							printf("%s", p[j].enrol[i].subjectName);
							printf("%.2f\n", p[j].enrol[i].marks);
						}
					}
				}
				printf("~\n");
				break;
			
			case 3:
				printf("Choose what you want to delete...");
				fgets(temp, 10, stdin);
				delete = atoi(temp);
				// Loop so search for the number to be deleted.
				for(j=count - 1; j>=0 && p[j].id != delete; j--) {}
				// Number is found.
				if(delete == p[j].id) {
					printf("Deletion successful ...\n");
					// A value of 0 indicates the value is deleted.
					p[j].id = 0;
					// I refuse to zero the other values because I'm lazy.
				} else {
					printf("Number not in the list ...\n");
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
