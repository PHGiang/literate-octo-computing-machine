#ifndef _MYQUEUE_H
#define _MYQUEUE_H

struct node {
	int value; 
	struct node * next; 
}; 

struct queue {
	struct node * front; 
	struct node * rear; 
	int size; 
}; 

/*make a new queue with zero node*/
void queue_init(struct queue *q); 

/*addend a node at the rear of the queue*/
void queue_push(struct queue *q, int val); 

/*remove a node in front of the queue,
 return that node's value*/
int queue_pop(struct queue *q); 

/*print a queue from the frist to the last node*/
void queue_print(struct queue *q); 

#endif
