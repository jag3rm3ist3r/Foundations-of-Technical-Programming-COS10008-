#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) {
	FILE * fptr = NULL;
	if(argc == 2) {
		if((fptr = fopen(argv[1], "w")) == NULL) {
			return 1;
		}
	} else {
		return 1;
	}


	typedef struct studentStruct {
		int ID;
		char name[10];
		float mark;
	} studentStruct;

	size_t Students_len = 3;
	studentStruct Students[3];
	Students[0].ID = 1;
	strcpy(Students[0].name, "Bob");
	Students[0].mark = 12.34;

	Students[1].ID = 2;
	strcpy(Students[1].name, "Jane");
	Students[1].mark = 56.78;

	Students[2].ID = 3;
	strcpy(Students[2].name, "Fred");
	Students[2].mark = 91.01;

	for(int i = 0; i < Students_len; i++) {
		fprintf(
				fptr,
				"ID:%d\n"
				"Name:%s\n"
				"Mark:%.2f\n",
				Students[i].ID,
				Students[i].name,
				Students[i].mark
			   );
	}

	fclose(fptr);


	return 0;
}
