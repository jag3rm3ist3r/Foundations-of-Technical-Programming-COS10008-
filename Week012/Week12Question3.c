#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
	FILE * fptr = NULL;
	if(argc == 2) {
		if((fptr = fopen(argv[1], "r")) == NULL) {
			printf("File failed to open.");
			return 1;
		}
	} else {
		printf("One argument accepted, no more, no less.\n");
		return 1;
	}


	char * line = NULL;
	size_t len = 0;
	ssize_t line_len;
	printf("\n");
	while((getline(&line, &len, fptr)) != -1) {
		int ID;
		sscanf(line, "ID:%d", &ID);
		printf("ID: %d\n", ID);

		getline(&line, &len, fptr);
		char * name;
		sscanf(line, "Name:%s", name);
		printf("Name: %s\n", name);

		getline(&line, &len, fptr);
		float mark;
		sscanf(line, "Mark:%f", &mark);
		printf("Mark: %.2f\n\n", mark);
	}


	fclose(fptr);


	return 0;
}


