/*
============================================================================
Name : 29.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to remove the message queue.
Date: 18th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/msg.h>
int main() {

    key_t msg_key = ftok(".",2);
    int msg_id = msgget(msg_key, IPC_CREAT | 0644);
    
    if (msgctl(msg_id, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        return 1;
    }

    printf("Message queue deleted!\n");

    return 0;
}
/*
Output:
$ gcc 29.c && ./a.out 
Message queue deleted!

$ ipcs -q
------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages  
*/