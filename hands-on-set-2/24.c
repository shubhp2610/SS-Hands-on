/*
============================================================================
Name : 24.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to create a message queue and print the key and message queue id.
Date: 18th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/msg.h>
int main() {
    key_t msg_key = ftok(".",2);
    printf("Message queue key : %X\n",msg_key);
    
    int msg_id = msgget(msg_key, IPC_CREAT | IPC_EXCL | 0644);
    printf("Message queue id : %d\n",msg_id);
    
    return 0;
}
/*
Output:
$ gcc 24.c && ./a.out 
Message queue key : 2051E90
Message queue id : 5

Running again 
$ gcc 24.c && ./a.out 
Message queue key : 2051E90
Message queue id : -1
*/