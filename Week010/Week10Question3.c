#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
 * <rant>
 * STOP PUTTING SPACES IN THE PDF FILENAMES.
 * A FILENAME IS NOT AN ESSAY, IT SHOULD NEVER HAVE SPACES IN IT.
 * I HAVE TO TYPE THEM INTO A TERMINAL TO OPEN OR MOVE THEM.
 * IT'S EXTREMELY ANNOYING TO TYPE ON LINUX SINCE I HAVE TO \ ESCAPE EACH ONE
 * AND IT CAUSES WINDOWS TO HIT THE FILENAME/PATH LENGTH CAP.
 * USE DASHES AND/OR UNDERSCORES WHERE ABSOLUTELY NECESSARY.
 * </rant>
 */


int main(void) {
	typedef enum {PASS, FAIL}pass_or_fail;

	typedef struct SubjectStruct {
		int subjectID;
		char subjectName[50];
		int mark;
	} Subject;

	typedef struct StudentStruct {
		int studentID;
		char studentName[50];
		size_t subjects_len;
		Subject subjects[3];
		pass_or_fail status;
	} Student;


	void inputChar(char input[]) {
		fflush(stdin);
		fgets(input, 50, stdin);
	}

	int inputInt(void) {
		char input[55];
		fflush(stdin);
		fgets(input, 50, stdin);
		return atoi(input);
	}

	/* Remove the \n (newline) character from the string. */
	void removeNewline(char string[]) {
		for(int i = 0; i < strlen(string); i++) {
			if(string[i] == '\n') {string[i] = '\0';}
		}
	}

	void createStudent(Student * s) {
		/* Input student ID */
		printf("Enter student ID: ");
		s->studentID = inputInt();

		/* Input student name */
		printf("Enter student name: ");
		char user_input_char[55];
		inputChar(user_input_char);
		strcpy(s->studentName, user_input_char);
		removeNewline(s->studentName);
		

		s->status = PASS;
		for(int i = 0; i < s->subjects_len; i++) {
			printf("Subject %d\n", i + 1);
			/* Fill subject IDs. */
			printf("Input the subject id for %s: ", s->studentName);
			s->subjects[i].subjectID = inputInt();

			/* Fill subject names.*/
			printf(	"Input the name of the subject with ID - %d: ",
					s->subjects[i].subjectID);
			inputChar(user_input_char);
			strcpy(s->subjects[i].subjectName, user_input_char);
			removeNewline(s->subjects[i].subjectName);

			/* Fill marks for subject. */
			printf("Input the student's mark for this subject: ");
			s->subjects[i].mark = inputInt();
			/* Assign the fail status to the student if any of the scores are
			 * below 50. */
			if(s->subjects[i].mark < 50) {
				s->status = FAIL;
			}
		}
		printf("\n");
	}


	void displayStudent(Student * s) {
		printf("Subjects for %s (%d)\n", s->studentName, s->studentID);
		printf("Subject ID	Name	Mark\n");
		for(int i = 0; i < s->subjects_len; i++) {
			printf(	"%d		%s	%d\n",
					s->subjects[i].subjectID,
					s->subjects[i].subjectName,
					s->subjects[i].mark);
		}
		if(s->status == FAIL) {
			printf("Status: FAIL\n");
		} else {
			printf("Status: PASS\n");
		}
	}


	Student Students[1];
	Students[0].subjects_len = 3;
	strcpy(Students[0].studentName, "Boris Johnson");
	Student * stuptr = Students;
	createStudent(stuptr);
	displayStudent(stuptr);


	return 0;
}

