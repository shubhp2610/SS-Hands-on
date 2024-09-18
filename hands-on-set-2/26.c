/*
============================================================================
Name : 26.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to send messages to the message queue. Check $ipcs -q
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
    printf("Enter message : ");
    scanf(" %[^\n]",mymsg.mtext);
    if(msgsnd(msg_id, &mymsg, sizeof(mymsg.mtext), IPC_NOWAIT) == -1){
        perror("msgsnd");
        return 1;
    }
    printf("Message added to queue!\n");
    return 0;
}
/*
Output:
$ gcc 26.c && ./a.out 
Enter message : hello queue
Message added to queue!

$ ipcs -q
------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x02051e90 5          ubuntu     644        200          1
*/