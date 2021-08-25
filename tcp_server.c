#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main() {
          char server_message[256] = "Server opened";
          
          //Creating the server socket
          int server_socket;
          server_socket = socket(AF_INET, SOCK_STREAM, 0);
          
          //Defining the address of server
          struct sockaddr_in server_address;
          server_address.sin_family = AF_INET;
          server_address.sin_port = htons(3000);
          server_address.sin_addr.s_addr = INADDR_ANY;
          
          //Bind the socket to our specified IP and port
          bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
          
          //Listen
          listen(server_socket, 5);
          
          int client_socket;
          client_socket=accept(server_socket, NULL, NULL);
          
          //Sending data
          send(client_socket, server_message, sizeof(server_message), 0);
          
          //Close the socket
          close(server_socket);
          return 0;
}
