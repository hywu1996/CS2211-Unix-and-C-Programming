/* printarray.c - HARRY WU (250797407) */
/*
Prints the value and address from an array with 9 values
*/


#include <stdio.h>
int main( )
{
 	int i;

 	//3d. Rewrite arr as pointer (and initialize with the same integer values)
 	int *arr;
 	arr = (int[9]) { 12, 23, 34, 45, 56, 67, 78, 89, 90 };

 	// 3a. Introduce int *p and point it to arr
 	int *p;
 	p = &arr[0];

 	// print the value and the address of each element of array
	for ( i = 0 ; i < 9 ; i++ )
	{
		//3b. Rewrite printf fucntion to use *p instead of arr[i]
		printf("arr[%d]: value is %d and address is %d\n", i, p[i], &p[i]);	
	}

	printf("\n\n");

	//3c. printf using pointer *p and using pointer arithmatic
	int *q;
	q = &arr[0];
	for (p; p < &arr[9]; p++) {
		printf("arr[%d]: value is %d and address is %d\n", p-q, *p, p);
	}


	return 0;
}
