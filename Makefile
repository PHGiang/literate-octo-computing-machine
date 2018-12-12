go_backn_r: go_backn_r.o my_sock_recv.o my_array.o 
	gcc go_backn_r.o my_sock_recv.o my_array.o -o go_backn_r

go_backn_r.o: go_backn_r.c my_sock_recv.h my_array.h
	gcc -c go_backn_r.c

sel_rep_s: sel_rep_s.o my_socket.o my_selective_lib.o \
			my_array.o my_queue.o
	gcc sel_rep_s.o my_socket.o my_selective_lib.o \
	my_array.o my_queue.o -o sel_rep_s 

sel_rep_r: sel_rep_r.o my_sock_recv.o my_array.o 
	gcc sel_rep_r.o my_sock_recv.o my_array.o -o sel_rep_r 

sel_rep_r.o: sel_rep_r.c my_sock_recv.h my_array.h
	gcc -c sel_rep_r.c 

my_sock_recv.o: my_sock_recv.c my_sock_recv.h
	gcc -c my_sock_recv.c 

sel_rep_s.o: sel_rep_s.c my_selective_lib.h \
		my_socket.h my_queue.h my_array.h 
	gcc -c sel_rep_s.c

my_selective_lib.o: my_selective_lib.c my_selective_lib.h \
	my_socket.h my_queue.h my_array.h
	gcc -c my_selective_lib.c

my_socket.o: my_socket.c my_socket.h
	gcc -c my_socket.c 

my_array.o: my_array.c my_array.h
	gcc -c my_array.c 

my_queue.o: my_queue.c my_queue.h
	gcc -c my_queue.c 

clean:
	rm *.o 