/*
============================================================================
Name : 34a.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to create a concurrent server.
                b. use pthread_create
Date: 19th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/socket.h>

void *request_handeler(void * argv){
    int new_socket_dec = *((int *)argv);
    char buffer[200];
    memset(buffer, 0, sizeof(buffer)); 
    read(new_socket_dec, buffer, sizeof(buffer) - 1);
    printf("Message from client: %s\n", buffer);
    write(new_socket_dec, "ACK from Server\n", 17);
    close(new_socket_dec);  
    return NULL;
}

int main() {
    pthread_t thread;
    struct sockaddr_in server, client;
    int socket_dec, new_socket_dec;

    socket_dec = socket(AF_UNIX, SOCK_STREAM, 0);

    server.sin_family = AF_UNIX;
    server.sin_port = htons(8888);
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
    while(1){
        printf("Waiting for client...\n");
        new_socket_dec = accept(socket_dec, (void*)&client, &sizeof_client);
        int *new_sock = malloc(sizeof(int));
        *new_sock = new_socket_dec;
        pthread_create(&thread, NULL, request_handeler, (void *) new_sock);
    }
    pthread_join(thread,NULL);
    close(new_socket_dec);
    close(socket_dec);
    return 0;
}


/*
Output:
$ gcc 34b.c && ./a.out
Socket server started on port 8888...
Waiting for client...
Message from client: Hello Server

Waiting for client...
Message from client: Hello Server

Waiting for client...
Message from client: Hello Server
*/