#include <stdio.h>
#include "my_selective_lib.h"
#include "my_socket.h"
#include "my_array.h"

void init_frame(int *frame, int f, int buf_size) {
	for (int i = 0, j = 1; i < f; i++) {
		frame[i] = j;
		j = (j == buf_size) ? 1: j+1;  
	}
	array_print(frame, f); 
}

int send_window(struct queue *q, int sock, int *arr, int win_size) {
	char b[NUMBUF]; 
	int tmp;
	int cnt = 0;  
	for (int i = 0; i < q->size; i++) {
		queue_print(q); 
		tmp = queue_pop(q); 
		conv_alpha(b, tmp); 
		send(sock, b, sizeof(b), 0); 
		printf("\nFrame %s sent", b); 
		queue_print(q); 
		printf("\nFrame %d pushed into copy", tmp); 
		printf("\n--------------------------");
		array_push(arr, tmp, win_size); 
		array_print(arr, win_size); 
		cnt++; 
	}
	return cnt; 
}

void received_ack(struct  queue *q, int ack, int *arr, int * frame, int win_size, int f, int *f_cur) {
	int tmp; 
	printf("\nReceived ACK %d", ack);
	array_search(arr, win_size, ack, delete); 
	array_print(arr, win_size); 
	if (*f_cur == f) 
		return; 
	tmp = frame[*f_cur]; 
	queue_push(q, tmp); 
	printf("\nFrame %d pushed into the window", tmp);
	queue_print(q);  
	printf("\nframe current = %d", *f_cur); 
	*f_cur = *f_cur + 1; 
}

void received_nak(int sock, char b[], int *arr, int win_size) {
	char tmp[NUMBUF]; 
	int e = conv_int(b); 
	printf("\nReceived NAK %d", e); 
	if (array_search(arr, win_size, e, search) == 1) {
		conv_alpha(tmp, e); 
		send(sock, tmp, sizeof(tmp), 0); 
		printf("\nFrame %s re-sent to receiver", tmp); 

	}
} 

void queue_setup(struct queue *q, int *frame, int *f_cur, int win_size) {
	printf("\nQUEUE SETUP "); 
	for (int i = 0; i < win_size; i++) {
		int tmp = frame[*f_cur]; 
		queue_push(q, tmp);
		printf("\nFrame %d pushed into the window", tmp);
		*f_cur = *f_cur + 1;
		printf("\nframe current = %d", *f_cur);   
	}	
	queue_print(q); 
}
