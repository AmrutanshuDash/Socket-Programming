#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>

int main() {
          //Creating a socket
          int network_socket;
          network_socket=socket(AF_INET, SOCK_STREAM, 0);
          
          //Specify an address for the socket
          struct sockaddr_in server_address;
          server_address.sin_family = AF_INET;
          server_address.sin_port = htons(3000);
          server_address.sin_addr.s_addr = INADDR_ANY; //connects to 0.0.0.0 automatically
          
          //Call the connect function
          int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
          
          //Check for error with the connection
          if(connection_status == -1){
                    printf("Error detected.");
          }
          
          //Receive data from the server
          char server_response[256];
          recv(network_socket, &server_response, sizeof(server_response) , 0);
          
          //Print the server's response
          printf("Data received from server: %s\n", server_response);
          
          //Close the socket
          close(network_socket);
          return 0;
}

