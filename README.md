# Communications System 
In this project, i use socket programing to simulate operation mechanism of selective repeat protocols and go back n protocols. 
Sever can be simulated in file sel_rep_s.c (selective repeat sender), this can be used for both the sender of selective repeat protocols and go-back-n protocols 
Client for selective repeat protocols is described in sel_rep_r.c(selective repeat receiver)
Client for go-back-n protocols is describled in file go_backn_r.c(go back n receiver)
Makefile is included. You must add IPAddress as the second parameter of the sender when running receiver's file.
This can run in two different computers or just one. 
