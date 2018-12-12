#ifndef MYSOCKRECV_H_
#define MYSOCKRECV_H_
#include <sys/socket.h>
#define PORT 3940
	int sock_recv_setup(char sevr[]); 
	void sock_recv_close(int sock); 
#endif 