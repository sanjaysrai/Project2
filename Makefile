CC = gcc

all: client

client: client.c

	$(CC) client.c -o client

server: server.c
	
	$(CC) server.c -o server

clean:
	rm client server 

