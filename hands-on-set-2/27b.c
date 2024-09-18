/*
============================================================================
Name : 27b.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to receive messages from the message queue.
                b. with IPC_NOWAIT as a flag
Date: 18th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/msg.h>
#include <errno.h>
int main() {
    
    struct msgbuf {
        long mtype;    
        char mtext[200]; 
    } mymsg;


    key_t msg_key = ftok(".",2);
    int msg_id = msgget(msg_key, IPC_CREAT | 0644);
    mymsg.mtype = 1;
    
    if(msgrcv(msg_id, &mymsg, sizeof(mymsg.mtext), mymsg.mtype, IPC_NOWAIT) == -1){
        perror("msgrcv");
        return 1;
    }
    printf("Message from queue : %s\n",mymsg.mtext);
    return 0;
}
/*
Output:
$ gcc 27b.c && ./a.out 
Message from queue : hello queue

$ gcc 27b.c && ./a.out 
msgrcv: No message of desired type
*/