/*
============================================================================
Name : 33_server.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to communicate between two machines using socket.
Date: 19th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
int main() {
    struct sockaddr_in server, client;
    int socket_dec, new_socket_dec;
    char buffer[200];

    socket_dec = socket(AF_UNIX, SOCK_STREAM, 0);

    server.sin_family = AF_UNIX;
    server.sin_port = htons(8889);
    server.sin_addr.s_addr = INADDR_ANY; 

    if (bind(socket_dec, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("bind");
        close(socket_dec);
        return 1;
    }

    printf("Socket server started on port 8888...\n");
    if (listen(socket_dec, 5) < 0) {
        perror("listen");
        close(socket_dec);
        return 1;
    }

    int sizeof_client = sizeof(client);

    new_socket_dec = accept(socket_dec, (void*)&client, &sizeof_client);
    
    memset(buffer, 0, sizeof(buffer)); // Clear the buffer
    read(new_socket_dec, buffer, sizeof(buffer) - 1); // Read data
    printf("Message from client: %s\n", buffer);

    write(new_socket_dec, "ACK from Server\n", 17);

    close(new_socket_dec);
    close(socket_dec);

    return 0;
}


/*
Output:
$ gcc 33_server.c && ./a.out
Socket server started on port 8888...
Message from client: Hello Server

*/