/*
============================================================================
Name : 33_client.c
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
#include <errno.h>
#include <sys/socket.h>
int main() {
    struct sockaddr_in server;
    int socket_dec;
    char buffer[200];

    socket_dec = socket(AF_UNIX, SOCK_STREAM, 0);

    server.sin_family = AF_UNIX;
    server.sin_port = htons(8888);
    server.sin_addr.s_addr = INADDR_ANY; 

    if (connect(socket_dec, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("connect");
        close(socket_dec);
        return 1;
    }

    write(socket_dec, "Hello Server\n", 14);

    memset(buffer, 0, sizeof(buffer));
    read(socket_dec, buffer, sizeof(buffer));
    printf("Message from server: %s\n", buffer);

    close(socket_dec);

    return 0;
}

/*
Output:
$ gcc 33_client.c && ./a.out
Message from server: ACK from Server
*/