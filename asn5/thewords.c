/*Sort a list of up to 50 words of length 20 to be entered in by the user*/
/*HARRY WU 250797407*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 50
#define WORD_LENGTH 20

/*
Bubble sort function used to sort the array of words
Receives the array to be sorted and the length of the array as arguments
*/
void bubbleSort(char *a[], int len) {
	int i, j;
	char temp[MAX_WORDS];

	for(i=0; i < len; i++) {

		for(j=i+1; j<len; j++) {

			if(strcmp(a[i], a[j])>0){
				strcpy(temp, a[i]);
				strcpy(a[i], a[j]);
				strcpy(a[j], temp);
			}
		}
	}

}

/*
Print an array of strings in order from beginning to end
Receives the array to be sorted and the length of the array as arguments
*/
void printArray(char *a[], int len) {
	int i;
	for(i = 0; i < len; i++){
		printf("%s ", a[i]);
	}
}

/*
main function
*/
int main() {
	char **array;
	
	//allocate memory for an array of char pointers	
	array = malloc( MAX_WORDS * sizeof(char*) );

	int q;
	
	//allocate memory for each word for each char pointer
	for(q = 0; q < MAX_WORDS; q++) {
		array[q] = malloc( WORD_LENGTH * sizeof(char) );
	}

	int length = 0;
	char input[WORD_LENGTH];

	//take user input until nothing is entered
	for(q = 0 ; q < MAX_WORDS; q++) {
		printf("Enter word: ");
		gets(input);

		if(*input == NULL){
			q=MAX_WORDS;
			printf("\n");
		}

		else{
			strcpy(array[q], input);;
			length++;
		}
	}

	//sort the list
	bubbleSort(array, length);

	printf("In sorted order: ");

	//print sorted list
	printArray(array, length);

	printf("\n");
	free(array);


	return 0;

}


