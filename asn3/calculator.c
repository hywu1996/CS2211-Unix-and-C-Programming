#include <stdio.h>


/*allow user to choose an operation (a,s,m,d,q), the operand type and the two operands. runs endlessly until quit is chosen as an operation.*/
int main() {
	char choice1, choice2;    /*stores the operation chosen and operand type respectively*/
	int i1,i2;     /*stores the two integer operands*/
	float f1,f2;   /*stores the two float operands*/

	/*infinite for loop until q is chosen as an option*/
	for (;;) {
		/*select the operation*/
		printf ("--------------------------------------\n\n");
		printf ("Choose desired operation: ");
		scanf (" %c", &choice1);
		printf ("\n");

		/*repeatedly ask for valid operation until valid choice is entered*/
		while (!(choice1=='a' || choice1=='s' || choice1=='m' || choice1=='d' || choice1=='q')) {
			printf ("--------------------------------------");
			printf ("\n\nPlease enter a valid operation.\n");
			printf ("a - addition\n");
			printf ("s - subtraction\n");
			printf ("m - multiplication\n");
			printf ("d - division\n");
			printf ("q - quit\n\n");
			printf ("Choose desired operation: ");
			scanf ( " %c", &choice1);
			printf ("\n");
		}

		/*quit the program*/
		if (choice1=='q') {
			printf ("Quitting program.\n");
			return 0;
		}
		
		/*valid operation choice that is not quit*/
		else {
			
			/*select operand type*/
			printf ("\nType of operands? (i - integer, f - float): ");
			scanf (" %c", &choice2);
			
			/*invalid operand message and prompt again*/
			while (!(choice2=='f' || choice2=='i')) {
				printf ("\n--------------------------------------");
				printf ("\n\nPlease make a valid choice. (i - integer, f - float): ");
				scanf(" %c", &choice2);
			}

			
			/*integer-type operations*/
			if (choice2=='i') {

				/*select integer operands*/
				printf ("\n\nYou have selected to use integer operands.\n\n");
				printf ("Operand 1: ");
				scanf ("%d", &i1);
				printf ("Operand 2: ");
				scanf ("%d", &i2);

				/*perform selected operation with operands*/
				if (choice1=='a') {
					printf ("\n%d + %d = %d \n", i1, i2, i1+i2);
					printf ("\n--------------------------------------\n");

				}
				else if (choice1=='s') {
					printf ("\n%d - %d = %d \n", i1, i2, i1-i2);
					printf ("\n--------------------------------------\n");

				}
				else if (choice1=='m') {
					printf ("\n%d x %d = %d \n", i1, i2, i1*i2);
					printf ("\n--------------------------------------\n");

				}
				else {
					printf ("\n%d / %d = %d \n", i1, i2, i1/i2);
					printf ("\n--------------------------------------\n");

				}

			}
			
			/*float operations*/ 
			else {
				
				/*select float operands*/ 
				printf ("\n\nYou have selected to use float operands.\n\n");
				printf ("Operand 1: ");
				scanf ("%f", &f1);
				printf ("Operand 2: ");
				scanf ("%f", &f2);

				/*perform selected operations with operands*/
				if (choice1=='a') {
					printf ("\n%f + %f = %f \n", f1, f2, f1+f2);
					printf ("\n--------------------------------------\n");

				}
				else if (choice1=='s') {
					printf ("\n%f - %f = %f \n", f1, f2, f1-f2);
					printf ("\n--------------------------------------\n");

				}
				else if (choice1=='m') {
					printf ("\n%f x %f = %f \n", f1, f2, f1*f2);
					printf ("\n--------------------------------------\n");

				}
				else {
					printf ("\n%f / %f = %f \n", f1, f2, f1/f2);
					printf ("\n--------------------------------------\n");
				}
			}

		}
	}
}





