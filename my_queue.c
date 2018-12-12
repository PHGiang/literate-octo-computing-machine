#include <stdio.h>
#include <stdlib.h>
#include "my_queue.h"

void queue_init(struct queue *q) {
	q->size = 0; 
	q->front = NULL; 
	q->rear = NULL; 
}

void queue_push(struct queue *q, int val) {
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->value = val; 
	newNode->next = NULL; 
	q->size++; 
	if (q->front == NULL && q->rear == NULL) {
		q->front = q->rear = newNode; 
	} 
	else {
		q->rear->next = newNode; 
		q->rear = newNode; 
	}
}

int queue_pop(struct queue *q) {
	int tmp; 
	tmp = q->front->value;
	q->size--;  
	if (q->front->next == NULL) {
		q->front = q->rear = NULL; 
	}
	else {
		struct node *removeNode = q->front; 
		q->front = q->front->next; 
		removeNode->next = NULL; 
		free(removeNode); 
	}
	return tmp; 
}

void queue_print(struct queue *q) {
	printf("\nCURRENT QUEUE SIZE: %d\n", q->size); 
	struct node * node; 
	node = q->front; 
	int count = q->size; 
	while (count--) {
		printf("%d\t", node->value); 
		node = node->next; 
	}
}