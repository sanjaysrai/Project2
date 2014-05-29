#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h> 
#include <netdb.h>
#include <strings.h>
#include "packet.h"

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
	struct sockaddr_in serveraddr;	
	int n, serverlen;

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
	
	/* build the server's Internet address */
    	bzero((char *) &serveraddr, sizeof(serveraddr));
    	serveraddr.sin_family = AF_INET;
    	bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    	serveraddr.sin_port = htons(server_port_number);

    	/* build the request */
    	printf("Client: building file request\n");
    	struct packet req_pkt;
    	bzero((char *) &req_pkt, sizeof(req_pkt));
    	strcpy(req_pkt.data, filename);
    	req_pkt.length = sizeof(req_pkt.type) * 3 + strlen(filename) + 1;

    	/* send the request to the server */
    	serverlen = sizeof(serveraddr);
    	n = sendto(socket_fd, &req_pkt, req_pkt.length, 0, (struct sockaddr*) &serveraddr, serverlen);  
  
    	if (n < 0)
      		error("Client: ERROR in sendto");	
	return 0;
}
