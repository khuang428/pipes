compile: client.c server.c pipe_networking.h
	gcc client.c -o client
	gcc server.c -o server
	gcc pipe_networking.h -o network
