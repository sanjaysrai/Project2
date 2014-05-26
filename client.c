#include <stdio.h>

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
	int prob_loss;
	int prob_corruption;
	int server_port_number;
	char* server_hostname;
	char* filename;

	// Check to see if command line arguments are valid
	if(argc != 5)
	{
		perror("Usage: ./client server_hostname server_port_number ﬁlename prob_loss prob_corruption");
	}

	server_hostname = argv[1];
    	server_port_number = atoi(argv[2]);
    	filename = argv[3];
	prob_loss = argv[4];
	prob_corruption = argv[5];
	
	return 0;
}
