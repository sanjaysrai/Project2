#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>

// need to move this function to a seperate header file (used in both client.c and server.c)
void error(char *msg) 
{
    perror(msg);
    exit(1);
}

int main(int argc, char* argv[])
{
	int port_number;
	int socket_fd = 0;

	struct sockaddr_in server_address;

	if(argc != 2)
	{
		error("Usage: ./server port_number congestion_window_size prob_loss prob_corruption");
	}

	port_number = atoi(argv[1]);

   	
	socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    	if (socket_fd < 0)
       		error("ERROR opening socket");
    	memset(&server_address, '0', sizeof(server_address));

    	server_address.sin_family = AF_INET;
    	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    	server_address.sin_port = htons(port_number); 
    	if (bind(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0)
        	error("ERROR when binding");	
	
	return 0; 
}
