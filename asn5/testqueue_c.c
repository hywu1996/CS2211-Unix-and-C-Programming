/* LINK-LIST IMPLEMENTATION OF A QUEUE - HARRY WU (250797407) */
/* 
Uses a linked list up to 100 nodes to implement a queue. Each node stores that data item as well as a pointer to the next node.
Variable 'top' stores the beginning of the queue, 'bot' stores the next available spot of the queue.
'size' stores the number of items currently in the queue.
*/
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

//a node of the linked list. stores the data item and a pointer to the next node.
struct Node {
	Item data;
	struct Node *next;
};

struct Node* top;
struct Node* bot;
size_t size; 


//set the pointer of the first and last element to null. initialiizes and empty queue
void make_empty(void) {
	top = NULL;
	bot = NULL;
}

//check if the queue is empty (has 0 elements); returns true if empty, false otherwsise
bool is_empty(void) {
	if (size == 0 || top == NULL || bot == NULL) {
		return true;
	} 
	else {
		return false;
	}
}

//check if all 100 positions of queue is occupied; returns true if full, false otherwsise
bool is_full(void) {
	if (size == MAX_QUEUE_SIZE) {
		return true;
	}
	else {
		return false;
	}
}

//add an item to the back of the queue
void enqueue(Item i) {
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = i;
	newNode->next = NULL;
	if(is_empty()){
		top = bot = newNode;
		size += 1;
		return;
	}
	else if (!is_full()){
		bot->next = newNode;
		bot = newNode;
		size += 1;
	}
	else {
		printf("Queue is full. Cannot enqueue.\n");
	}

}

//remove and return the item at the front of the queue
Item dequeue(void) {
	struct Node *temp = top;
	
	if (is_empty()) {
		printf("Nothing to dequeue. Queue is empty.\n");
		return NULL;
	}
	else if (top == bot) {
		top = NULL;
		bot = NULL;
		size--;
	}
	else {
		top = top->next;
		size--;
	}

	Item deq = temp->data;
	free(temp);
	return deq;
}

//return the first item in the queue
Item first(void) {
	Item temp = NULL;

	if (!(is_empty())) {
		temp = top->data;
	}

	return temp;
}

//return the last item in the queue
Item last(void) {
	Item temp = NULL;

	if (!(is_empty())) {
		temp = bot->data;
	}

	return temp;
}

//main function: test enqueue and dequeue
int main() {
	printf("Link-List Implmentation of a Queue\n------------------------\n\n");

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
