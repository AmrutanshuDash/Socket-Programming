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

Funtions
Function	Description
socket()	Specifying the type of communication protocol (TCP based on IPv4, TCP based on IPv6, UDP). Where family specifies the protocol family (AF_INET for the IPv4 protocols), type is a constant described the type of socket (SOCK_STREAM for stream sockets and SOCK_DGRAM for datagram sockets.The function returns a non-negative integer number, similar to a file descriptor, that we define socket descriptor or -1 on error.
connect()	Function is used by a TCP client to establish a connection with a TCP server. where sockfd is the socket descriptor returned by the socket function.The function returns 0 if the it succeeds in establishing a connection (i.e., successful TCP three-way handshake, -1 otherwise.The client does not have to call bind() in Section before calling this function: the kernel will choose both an ephemeral port and the source IP if necessary.
bind()	Assigns a local protocol address to a socket. With the Internet protocols, the address is the combination of an IPv4 or IPv6 address (32-bit or 128-bit) address along with a 16 bit TCP port number. where sockfd is the socket descriptor, myaddr is a pointer to a protocol-specific address and addrlen is the size of the address structure. bind() returns 0 if it succeeds, -1 on error. This use of the generic socket address sockaddr requires that any calls to these functions must cast the pointer to the protocol-specific address structure. For example for and IPv4 socket structure
listen()	Function converts an unconnected socket into a passive socket, indicating that the kernel should accept incomingcconnection requests directed to this socket. where sockfd is the socket descriptor and backlog is the maximum number of connections the kernel should queue for this socket. The backlog argument provides an hint to the system of the number of outstanding connect requests that is should enqueue in behalf of the process. Once the queue is full, the system will reject additional connection requests. The backlog value must be chosen based on the expected load of the server.The function listen() return 0 if it succeeds, -1 on error.
accept()	Used to retrieve a connect request and convert that into a request. where sockfd is a new file descriptor that is connected to the client that called the connect(). The cliaddr and addrlen arguments are used to return the protocol address of the client. The new socket descriptor has the same socket type and address family of the original socket. The original socket passed to accept() is not associated with the connection, but instead remains available to receive additional connect requests. The kernel creates one connected socket for each client connection that is accepted.
send()	Socket endpoint is represented as a file descriptor, we can use read and write to communicate with a socket as long as it is connected. where buf and nbytes have the same meaning as they have with write. The additional argument flags is used to specify how we want the data to be transmitted. We will not consider the possible options in this course. We will assume it equal to 0. The function returns the number of bytes if it succeeds, -1 on error.
receive()	The recv() function is similar to read(), but allows to specify some options to control how the data are received. The function returns the length of the message in bytes, 0 if no messages are available and peer had done an orderly shutdown, or -1 on error.
close()	The normal close() function is used to close a socket and terminate a TCP socket. It returns 0 if it succeeds, -1 on error.
