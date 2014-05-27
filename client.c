#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h> 
#include <netdb.h>

// auxillary function to print out errors and exit to save space
void error(char* msg)
{
	//prints to standard error
	perror(msg);	
	//exit(0) is for success while exit one is for failure
	exit(1);
}

int main(int argc, char** argv)
{
	/* Declare variables to be used */
	int prob_loss;
	int prob_corruption;
	int server_port_number;
	char* server_hostname;
	char* filename;

	/* Check to see if command line arguments are valid */
	if(argc != 5)
	{
		perror("Usage: ./client server_hostname server_port_number ﬁlename prob_loss prob_corruption");
	}

	/* Initialize command line arguments */
	server_hostname = argv[1];
    	server_port_number = atoi(argv[2]);
    	filename = argv[3];
	prob_loss = atoi(argv[4]);
	prob_corruption = atoi(argv[5]);
	
	/* Create a UDP socket */
	int socket_fd;
	socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    	
	/* Check if socket was properly created */
	if (socket_fd < 0) 
        	error("ERROR opening socket");

	/*Get the DNS information from the server */ 
	struct hostent* server;
	server = gethostbyname(server_hostname);	
	if(server == NULL)
		perror("Error: Not able to get server host by name");

	return 0;
}
