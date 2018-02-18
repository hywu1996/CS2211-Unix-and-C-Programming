/*HARRY WU - 250797407*/
/*Header file with prototypes and typedef for implementing a queue*/

#ifndef QUEUE_H

#define QUEUE_H
#include <stdbool.h>

/*typedef for what will be stored in the queue */
typedef int Item;

/*initialize an empty queue*/
void make_empty();

/*check if queue is empty*/
bool is_empty();

/*check if queue is full*/
bool is_full();

/*add an item to the queue*/
void enqueue(Item data);

/*remove an item from the queue*/
Item dequeue();

/*find the first item in the queue*/
Item first();

/*find the last item in the queue*/
Item last();


#endif
