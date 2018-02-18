#include <stdio.h>

/*Using two four loops to print a pyramid of stars*/

int main() {
	int line, star; /*store the line number and the stars to be printed*/
	
	/*outside for loop specifies the line and how many stars we need for that line. Between 1 and 10.*/
	for (line=1; line<=10; line++) {
		
		/*nested for loop will print stars until we have the same number of stars as the line number*/
		for (star=1; star<=line; star++) {
			printf("*");
		}
		printf("\n"); /*print a new line to start the next row of stars*/
	}
	return 0;

}
