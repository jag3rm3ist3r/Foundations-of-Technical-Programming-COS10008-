#include <stdio.h>
#include <stdlib.h>

int main()
{
	/* Declare like 5 at once but then one separately for no reason. */
	int option=0, j=0, k=0, delete=0, position=0;
	int count=0; 	// keeps the count of numbers added
	int *p = NULL;
	/* This is entirely useless as it is used to create two if statements where
	 * there should only be one. This could have been declared with the rest of
	 * the ints. */
	int flag = 0; //variable to indicate whether the number to delete is found or not
	
	/* This isnt printed when the menu displays, only when the program starts,
	 * not sure if that's intentional. */
	printf("~~~~~Integer Storage~~~~~\n");
	/* Why not just create a function that returns a different value if you
	 * want to break the loop? */
	while (1)
	{
		printf("1- Add new Number\n");
		printf("2- Display Number(s)\n");
		printf("3- Delete a Number \n");
		printf("4- Quit\n");
		printf("Option...");
		scanf("%d",&option);
		
		/* None of these lines are correctly indented. */
		switch (option)
		{
			/* Why is count not incremented at the start? Writing count+1 into
			 * the memory allocation is completely unintuitive. */
			case 1: p = realloc(p, sizeof(int)*(count+1)); //using realloc memory is requested for the new number
				printf("Your Number...1 or above");
				/* Because you didn't increment count it's now the correct
				 * number for the array, but that isn't usually the case so this
				 * code just looks funny. */
				scanf("%d", &p[count]);
				count++;
				printf("\n");
				break;
		
		case 2: printf("~~~~~Your Numbers(s)~~~~~\n");
			for (j=0; j<count; j++)
			{
				/* Why isn't this in brackets when the rest of the code is? */
				if(p[j] != 0)
					printf("~%d",p[j]);
			}
			/* Why are these two separate lines? */
			printf("~");
			printf("\n");
			break;
		
				/* This k=count is completely unnecessary, just use count. */
		case 3: k=count;
			/* If you had declared this inside of a function that loops you
			 * wouldn't have to reset it here. */
			flag=0;
			printf("Choose what you want to delete...");
			scanf("%d", &delete);
			/* Since j is equal to k here and k is the size of the array j will
			 * always be one off the end of the array for the first time around
			 * the loop and read outside of the heap. */
			for (j=k; j>=0; j--)		//loop to search for the number to be deleted 
			{
				if (delete == p[j])		//if the number is found
				{
					flag = 1;
					p[j] = 0 ;
					/* Why is there a comment on a bracket close to describe
					 * what was written on the previous line? */
				}					// Assign 0 to indicate the value is deleted
			}
			/* This makes no sense, why not just do this in the above if
			 * statement? Why are there no brackets here but there are above? */
			if(flag==0)
				printf("Number not in the list ...\n");
			else
				printf("Deletion successful ...\n");
			
			printf("\n");
			/* This doesn't clean up the excess memory allocated to the
			 * array. */
			break;
		
			/* Just end the program without free() ing the memory. */
		case 4: 	return 0;
	}
/* More identation issues. */
}
return 0;
}
