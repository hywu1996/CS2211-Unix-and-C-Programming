/* ARRAY IMPLMENTATION OF QUEUE - HARRY WU (250797407) */
/* 
Uses an array with max size of 100 to implement a queue.
Variable 'top' stores the beginning of the queue, 'bot' stores the next available spot of the queue.
'size' stores the number of items currently in the queue.
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#define MAX_QUEUE_SIZE 100

size_t top, bot, size;

Item array[MAX_QUEUE_SIZE]; 


//initialize an empty queue by setting all variables to 0
void make_empty(){
	top = 0;
	bot = 0;
	size = 0;
}

//check if the queue is empty (has 0 elements); returns true if empty, false otherwsise
bool is_empty() {
	if (size == 0) {
		return true;
	} 
	else {
		return false;
	}
}

//check if all 100 positions of queue is occupied; returns true if full, false otherwsise
bool is_full() {
	if (size == MAX_QUEUE_SIZE) {
		return true;
	}
	else {
		return false;
	}
}

void enqueue(Item data) {
	if (!(is_full())) {
		array[bot] = data;
		bot = (bot+1) % MAX_QUEUE_SIZE;
		size++;
	}
	else {
		printf("Queue is full. Cannot enqueue.\n");
	}
}
Item dequeue() {
	Item temp = NULL;
	if (is_empty()) {
		printf("Nothing to dequeue. Queue is empty.\n");
	}
	else {
		temp = array[top];
		array[top] = NULL;
		top = (top+1) % MAX_QUEUE_SIZE;
		size--;
	}
	return temp;
}

Item first() {
	Item temp = NULL;
	if (!(is_empty())) {
		temp = array[top];
	}
	return temp;
}
Item last() {
	Item temp = NULL;
	if (!(is_empty())) {
		temp = array[bot-1];
	}
	return temp;
}


int main() {
	printf("Array Implmentation of a Queue\n------------------------\n\n");

	make_empty();
	
	enqueue(45);
	enqueue(67);
	enqueue(78);
	enqueue(34);
	enqueue(675);
	enqueue(23);
	enqueue(756);
	
	printf("Dequeue 2 numbers:\n");
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());

	enqueue(42);

	printf("Dequeue the rest of the numbers on the queue:\n");
	Item DQdata = dequeue();
	while(DQdata != NULL){
		printf("%d\n", DQdata);
		DQdata = dequeue();
	}
	return 0;
}

