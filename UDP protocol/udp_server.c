#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h> 
#include <string.h> 

#define MAX_MSG 100
#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 9227

 main( ) {
  int sd, rc, n, cliLen;
  struct sockaddr_in cliAddr, servAddr;
  char msg[MAX_MSG];

  /**********************************/ 

  /* build server address structure */

  /**********************************/  

  bzero((char *)&servAddr, sizeof(servAddr));
  servAddr.sin_family = AF_INET;
  servAddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
  servAddr.sin_port = htons(SERVER_PORT);

  /**************************/ 

  /* create datagram socket */

  /**************************/ 

  sd=socket(AF_INET, SOCK_DGRAM, 0);
  printf("datagram socket created succefully\n");

  /**************************/ 

  /* bind local port number */

  /**************************/ 

  bind (sd, (struct sockaddr *) &servAddr,sizeof(servAddr));
  printf("successfully bound local address\n");
  printf("waiting for data on port UDP %u\n", SERVER_PORT);

  while(1) {
 
    /* init buffer */

    memset(msg,0x0,MAX_MSG);

    /****************************/

    /* receive data from client */

    /****************************/  

    cliLen = sizeof(cliAddr);
    n = recvfrom(sd, msg, MAX_MSG, 0, (struct sockaddr *) &cliAddr, &cliLen);
    printf("from %s: UDP port %u : %s \n", 
    inet_ntoa(cliAddr.sin_addr), ntohs(cliAddr.sin_port),msg);
  }
return 0;

}
