#include <stdio.h>
#include <stdlib.h>
#include "my_selective_lib.h"
#include "my_socket.h"
#include "my_array.h"
#include "my_queue.h"

#define W_SIZE 3
#define B_SIZE 8 
#define FRAME_MAX 100

int main() {
	struct queue window; 
	queue_init(&window); 
	int frame[FRAME_MAX];
	int copy[W_SIZE]; 
	int n_resent_frame = 0; 
	int n_sent_frame = 0;
	int f_cur = 0;  
	int f = 0; 
	int fd[2];
	int tmp;  
	char tmp_s[NUMBUF]; 
	char tmp_r[NUMBUF]; 
	int count = 0; 

	socket_setup(fd); 
	int sockfd = fd[0]; 
	int new_fd = fd[1]; 

	printf("\nEnter the number of Frames: "); 
	scanf("%d", &f); 
	conv_alpha(tmp_s, f); 
	printf("send %ld", send(new_fd, tmp_s, sizeof(tmp_s), 0));  
	init_frame(frame, f, B_SIZE);
	array_init(copy, W_SIZE); 
	queue_setup(&window, frame, &f_cur, W_SIZE);
	while (count <= f) {
		n_sent_frame += send_window(&window, new_fd, copy, W_SIZE); 
		recv(new_fd, tmp_r, sizeof(tmp_r), 0); 
		if (tmp_r[0] == 'N') {
			n_resent_frame++; 
			received_nak(new_fd, tmp_r, copy, W_SIZE); 
		}
		else {
			tmp = atoi(tmp_r); 
			count++; 
			received_ack(&window, tmp, copy, frame, W_SIZE, f, &f_cur); 
		}
		printf("\n--------------------------");
	}

	printf("\nNumber of frames: %d", f); 
    printf("\nNumber of total sent frames: %d", n_sent_frame + n_resent_frame);  
    printf("\nNumber of resent frames: %d", n_resent_frame);
	socket_close(sockfd); 
	printf("\n"); 
	return 0; 
}