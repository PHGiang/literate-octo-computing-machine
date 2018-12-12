#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_socket.h"
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

void *get_in_addr(struct sockaddr *sa) {
	return &(((struct sockaddr_in*)sa)->sin_addr); 
}

void socket_setup(int *fd) {
	int yes = 1; 
	struct sockaddr_storage their_addr; 
	int sockfd, new_fd; 
	struct sockaddr_in address; 
	char s[INET6_ADDRSTRLEN];
	int sin_size;  

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("socket failed"); 
		exit(EXIT_FAILURE); 
	}
	fd[0] = sockfd; 

	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
		perror("set sockopt failed"); 
		exit(1); 
	}

	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY; 
	address.sin_port = htons(PORT); 

	if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	}

	if (listen(sockfd, BACKLOG) < 0) {
		perror("listen failed"); 
		exit(EXIT_FAILURE); 
	}
	printf("server: waiting for connections ...\n"); 
	while(1) {
		sin_size = sizeof(their_addr); 
		new_fd = accept(sockfd, (struct sockaddr *) &their_addr, &sin_size); 
		if (new_fd == -1) {
			perror("accept failed"); 
			continue; 
		}

		inet_ntop(their_addr.ss_family, get_in_addr((struct sockaddr *)&their_addr), s, sizeof(s)); 
		printf("server: got connection from %s\n", s); 
		printf("\nTCP Connection Established.\n");
		break; 
	}
	fd[1] = new_fd; 
}

void socket_close(int sock) {
	close(sock); 	
}