# Socket-Programming
Collection of well commented socket codes of server &amp; client side using different protocols

A socket is the mechanism that most popular operating systems provide to give programs access to the network. It allows messages to be sent and received between applications (unrelated processes) on different networked machines.

Sockets are the low level endpoint used for processing information across a network. common networking protocols like HTTP, and FTP rely on sockets underneath to make connections.

The sockets mechanism has been created to be independent of any specific type of network. IP, however, is by far the most dominant network and the most popular use of sockets. This tutorial provides an introduction to using sockets over the IP network (IPv4).

![image](https://user-images.githubusercontent.com/68193810/130823650-6da559e5-3629-468c-b2b0-66fc8493b5c2.png)


Topics TCP/IP sockets
There are a few steps involved in using sockets:

Create the socket.
Identify the socket.
On the server, wait for an incoming connection.
On the client, connect to the server's socket.
Send and receive messages.
Close the socket.
Client Socket Workflow
Create a socket using the socket() function;
Connect the socket to the address of the server using the connect() function;
Send and receive data by means of the read() and write() functions.
socket() -------> connect() -------> recv()

Server Socket Workflow
Create a socket with the socket() function;
Bind the socket to an address using the bind() function;
Listen for connections with the listen() function;
Accept a connection with the accept() function system call. This call typically blocks until a client connects with the server.
Send and receive data by means of send() and receive().
socket() -------> bind() -------> listen() -------> accept()
 
