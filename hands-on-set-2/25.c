/*
============================================================================
Name : 25.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
                a. access permission
                b. uid, gid
                c. time of last message sent and received
                d. time of last change in the message queue
                d. size of the queue
                f. number of messages in the queue
                g. maximum number of bytes allowed
                h. pid of the msgsnd and msgrcv
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
    struct msqid_ds msg;
    msgctl(msg_id,IPC_STAT, &msg);
    printf("access permission : %o\n",msg.msg_perm.mode); //octal
    printf("uid : %d, gid : %d\n",msg.msg_perm.uid, msg.msg_perm.gid);
    printf("time of last message sent and received %ld\n", msg.msg_stime);
    printf("time of last change in the message queue %ld\n", msg.msg_ctime);
    printf("size of the queue : %ld bytes\n",msg.__msg_cbytes);
    printf("number of messages in the queue : %ld\n", msg.msg_qnum);
    printf("maximum number of bytes allowed : %ld\n", msg.msg_qbytes);
    printf("pid of the msgsnd : %d and msgrcv : %d\n", msg.msg_lspid, msg.msg_lrpid);    
    return 0;
}
/*
Output:
$ gcc 25.c && ./a.out 
access permission : 644
uid : 1000, gid : 1000
time of last message sent and received 1726680841
time of last change in the message queue 1726680825
size of the queue : 0 bytes
number of messages in the queue : 0
maximum number of bytes allowed : 16384
pid of the msgsnd : 20773 and msgrcv : 20885

*/