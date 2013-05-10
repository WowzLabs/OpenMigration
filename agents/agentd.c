/*
 * Daemon process for OpenMigration Client.
 * Draft version.
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


#define LOCAL_AGENT_PORT 8888
#define MAX_MSG 100

int main(int argc,char *argv[])
{
	int socket_d, rc;
	struct sockaddr_in	address;

	
	/*
	 * Define and intialize the socket structure.
	 * bind on port 8888
	 * listen for network packet.
	 */

	socket_d = socket(AF_INET, SOCK_DGRAM, 0);
	if(socket_d<0)
	{
			printf("Error in creating socket!!\n");
			return -1;
	}
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_port = htons(LOCAL_AGENT_PORT);

	rc = bind(socket_d, (struct sockaddr *) &address,sizeof(address));
	if(rc<0)
	{
			printf("Error in binding to port\n");
			return -1;
	}


	printf("Starting Agent..!\n");

	printf("Waiting for discovery packets\n");


}

#if 0
int main(int argc, char *argv[]) {
  
  int sd, rc, n, cliLen;
  struct sockaddr_in cliAddr, servAddr;
  char msg[MAX_MSG];

  /* socket creation */
  sd=socket(AF_INET, SOCK_DGRAM, 0);
  if(sd<0) {
    printf("%s: cannot open socket \n",argv[0]);
    exit(1);
  }

  /* bind local server port */
  servAddr.sin_family = AF_INET;
  servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servAddr.sin_port = htons(LOCAL_SERVER_PORT);
  rc = bind (sd, (struct sockaddr *) &servAddr,sizeof(servAddr));
  if(rc<0) {
    printf("%s: cannot bind port number %d \n", 
	   argv[0], LOCAL_SERVER_PORT);
    exit(1);
  }

  printf("%s: waiting for data on port UDP %u\n", 
	   argv[0],LOCAL_SERVER_PORT);

  /* server infinite loop */
  while(1) {
    
    /* init buffer */
    memset(msg,0x0,MAX_MSG);


    /* receive message */
    cliLen = sizeof(cliAddr);
    n = recvfrom(sd, msg, MAX_MSG, 0, 
		 (struct sockaddr *) &cliAddr, &cliLen);

    if(n<0) {
      printf("%s: cannot receive data \n",argv[0]);
      continue;
    }
      
    /* print received message */
    printf("%s: from %s:UDP%u : %s \n", 
	   argv[0],inet_ntoa(cliAddr.sin_addr),
	   ntohs(cliAddr.sin_port),msg);
    
  }/* end of server infinite loop */

return 0;

}
#endif
