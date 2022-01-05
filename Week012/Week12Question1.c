#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]) {
	if(argc != 3) {
		printf("Error, incorrect ammount of arguments.\n");
		return 1;
	}

	printf("\n");

	/* Debug info. *
	printf("argc : %d\n", argc);
	for(int i = 0; i < argc; i++) {
		printf("argv : %s\n", argv[i]);
	}
	/**/

	FILE * fptr;
	fptr = fopen(argv[1], "r");
	if(!fptr) {return 1;}


	/**
	printf("%s contents:\n", argv[1]);
	/**/

	/*
	int n;
	fscanf(fptr, "%d", &n);
	printf("%d\n", n);

	float f;
	for(int i = 0; i < 10; i++) {
		fscanf(fptr, "%f", &f);
		printf("%.1f	", f);

		fscanf(fptr, "%f", &f);
		printf("%.1f\n", f);
	}
	printf("\n");
	*/


	char * line = NULL;
	size_t number_of_lines = 0;
	size_t len = 0;
	ssize_t line_len;
	float val = 0.00;
	float average_val = 0.00;
	float maximum_val = 0.00;
	float minimum_val = 0.00;
	while((line_len = getline(&line, &len, fptr)) != -1) {
		/* Debug info. *
		printf("%d	-	", line_len);
		/**/
		/**
		printf("%s", line);
		/**/
		number_of_lines++;

		sscanf(line, "%*f %f", &val);

		if(minimum_val == 0.00) {minimum_val = val;}

		average_val += val;
		/* Debug info. *
		printf("average_val : %.2f\n", average_val);
		/**/
		if(val > maximum_val) {
			maximum_val = val;
		}
		if(val < minimum_val) {
			minimum_val = val;
		}
	}
	average_val /= number_of_lines - 1;

	printf("\n\n");
	/**
	printf("Number of lines: %d\n\n", number_of_lines);
	/**/
	if(line) {free(line);}

	fclose(fptr);


	fptr = fopen(argv[2], "w");
	if(!fptr) {return 1;}


	fprintf(fptr,
			"Number of sensor readings: %d\nAverage reading: %.2f\n"
			"Maximum reading: %.2f\nMinimum reading: %.2f\n",
			(number_of_lines - 1), average_val, maximum_val, minimum_val);


	fclose(fptr);


	return 0;
}
