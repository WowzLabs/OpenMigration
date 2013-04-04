/*
	Server starting point.
	This server does following things.
	
	1. Intializes the server
	2. Listen to client for connection.
	3. Maintains list of clients in hash with info like IP, protocol supported etc
	4. On cli requests, get information about client capablities.
	5. can trigger the migration task.

	File Organization
	=================

	*Network Module
		- NetworkCommunicator.c
	*Client Management
		- ClientManager.c
	*Parser Server-User interaction
		- CommandParser.c
	*Utils
		- Misc library functions. like khash, logger.

*/

#include <stdio.h>


int main()
{
	/*
		- Intialize the network module.
		- Listen for clients in listener thread.
		- spawn thread command-parser, which will wait for commands from user.
		
	*/

}
