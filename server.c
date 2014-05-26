#include <stdlib.h>
#include <stdio.h>

// need to move this function to a seperate header file (used in both client.c and server.c)
void error(char *msg) 
{
    perror(msg);
    exit(1);
}

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		error("Usage: ./server port_number congestion_window_size prob_loss prob_corruption");
	}
	
	return 0; 
}
