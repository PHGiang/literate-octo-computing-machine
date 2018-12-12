#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_sock_recv.h"
#include "my_array.h"

#define W_SIZE 3
#define P1 3
#define P2 0
#define NUMBUF 10

int main(int argc, char const *argv[]) {
	int sock; 
	int count = 0;
	int f = 0; 
	char tmp_r[NUMBUF]; 
	char tmp_s[NUMBUF]; 
	int tmp = 0; 
	int j = 0; 

	char serv[13];  
	if (argc != 2)  {
		fprintf(stderr,"usage: client hostname\n");
		exit(1); 
	}

	strcpy(serv, argv[1]); 
	sock = sock_recv_setup(serv); 
	printf("recv %ld", recv(sock, tmp_r, sizeof(tmp_r),0));
	f = atoi(tmp_r);
	printf("Number of frames: %s\n",tmp_r);

	while (1) {
		printf("recv %ld", recv(sock, tmp_r, sizeof(tmp_r), 0));
		tmp = atoi(tmp_r);  
		printf("\nReceived: %s", tmp_r); 
		j = rand()%P1; 
		printf("\nj = %d", j); 
		if (j == P2) {
			printf("\nFrame %s failed", tmp_r); 
			conv_alphaN(tmp_s, tmp); 
			send(sock, tmp_s, sizeof(tmp_s), 0); 
		}
		else {
			printf("\nFrame %s received", tmp_r);
			strcpy(tmp_s, tmp_r);  
			send(sock, tmp_s, sizeof(tmp_s), 0); 
			count += 1; 
			printf("Count = %d", count); 
			if (count == f)
				break; 
		}
		printf("\n--------------------------");
	}
	sock_recv_close(sock);
	printf("\n"); 
	return 0; 
}