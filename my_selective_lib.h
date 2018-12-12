#ifndef MYSELECTIVE_H 
#define MYSELECTIVE_H
#include "my_queue.h"
#define NUMBUF 10

/*init frame*/
void init_frame(int * frame, int f, int buf_size);

/*send value inside the window to client socket
return number of frames sent*/
int send_window(struct queue *q, int sock, int * arr, int win_size); 

void received_ack(struct  queue *q, int ack, int *arr, int *frame, int win_size, int f, int *f_cur); 
 
void received_nak(int sock, char b[], int *arr, int win_size); 

void queue_setup(struct queue *q, int *frame, int *f_cur, int win_size); 
#endif
