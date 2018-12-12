#ifndef MYSOCKET_H
#define MYSOCKET_H
#include <sys/socket.h>
#define PORT 3940
#define BACKLOG 10

/*get address of the socket just accepted*/
void *get_in_addr(struct sockaddr *sa); 

/*return socket server file description and client fd*/
void socket_setup(int *fd); 

/*sock is file description of client socket*/
void socket_close(int sock); 

#endif 
