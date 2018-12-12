#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_sock_recv.h"
#include "my_array.h"

#define W_SIZE 3
#define P1 3
#define P2 0
#define NUMBUF 10
#define B_SIZE 8

int main(int argc, char const *argv[]) {
	int sock;
	char serv[13];  
	char tmp_r[NUMBUF]; 
	char tmp_s[NUMBUF];
	int f = 0; 
	int tmp = 0; 
	int j = 0; 
	int count = 0; 

	if (argc != 2)  {
		fprintf(stderr,"usage: client hostname\n");
		exit(1); 
	}
	strcpy(serv, argv[1]); 
	sock = sock_recv_setup(serv); 
	printf("recv %ld", recv(sock, tmp_r, sizeof(tmp_r),0));
	f = atoi(tmp_r);
	printf("Number of frames: %s\n",tmp_r); 
	int expt = 1; 
	while (count < f) {
		printf("\n--------------------------");
		printf("\nexpect = %d", expt); 
		recv(sock, tmp_r, sizeof(tmp_r), 0);
		tmp = atoi(tmp_r);  
		printf("\nReceived: %s", tmp_r); 
		if (tmp == expt) {
			j = rand()%P1; 
			printf("\nj = %d", j); 
			if (j > P2) {
				printf("\nFrame %d received", tmp);
				strcpy(tmp_s, tmp_r); 
				send(sock, tmp_s, sizeof(tmp_s), 0);  
				count++; 
				printf("\nCount = %d", count);  
				expt = (expt == B_SIZE) ? 1: expt +1; 				
				continue; 
			}
		}
		printf("\nFrame %d failed", expt); 
		conv_alphaN(tmp_s, expt); 
		send(sock, tmp_s, sizeof(tmp_s), 0);

	}
	sock_recv_close(sock); 
	printf("\n"); 
	return 0; 
}