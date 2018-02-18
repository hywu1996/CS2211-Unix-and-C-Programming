#include <stdio.h>

/*Use a for loop for the numbers between 1 and 10 (inclusive) and print out the squared value*/

int main() {
	int num, num2; /*what we will store the number and its squre in */

	/*square the number and print it for each number between 1 and 10*/
	for (num=1 ; num<=10 ; num++ ) {
		num2 = num*num;
		printf ("%d\n", num2);
	}
	return 0;
}
