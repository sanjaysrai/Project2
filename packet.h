/*
	This is the data structure we are going to use for 
	our packet for our go-back-n implementation
*/


// What is the appropraite maximum size for the data?
#define SIZE 256

struct packet
{
	// Want to use an enum for type instead of an int
	int type;
	// Data in packet
	char data[SIZE];
	// The amount of space the packet takes
	int length;
	// current packets sequence number
	int sequence_number;
};
