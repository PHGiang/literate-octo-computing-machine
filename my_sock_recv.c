#include "my_sock_recv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

int sock_recv_setup(char serv[]) {
	int sock_fd; 
	struct sockaddr_in serv_addr; 
	if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("\nSocket creation error\n"); 
		exit(1); 
	}

	memset(&serv_addr, '0', sizeof(serv_addr)); 
	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 
	if (inet_pton(AF_INET, serv, &serv_addr.sin_addr) < 0) {
		printf("Invalid address\n"); 
		exit(1); 
	}
	if (connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		printf("Connection failed\n"); 
		exit(1);
	}
	printf("\nTCP Connection Established.\n"); 
	return sock_fd; 
}

void sock_recv_close(int sock) {
	close(sock); 
}