/*
============================================================================
Name : 28.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure)
Date: 19th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/msg.h>
#include <errno.h>
int main() {
    key_t msg_key = ftok(".",2);
    int msg_id = msgget(msg_key, IPC_CREAT | 0644);
    struct msqid_ds msqid;
    if(msgctl(msg_id,IPC_STAT, &msqid)){
        perror("msgctl fetch");
        return 1;
    }
    printf("Current msg queue permission : %o\n",msqid.msg_perm.mode);
    printf("Updating msg queue permission to 0600\n");
    msqid.msg_perm.mode = 0600;
    if(msgctl(msg_id,IPC_SET, &msqid)){
        perror("msgctl set");
        return 1;
    }
        if(msgctl(msg_id,IPC_STAT, &msqid)){
        perror("msgctl fetch");
        return 1;
    }
    printf("Updated msg queue permission : %o\n",msqid.msg_perm.mode);
    return 0;
}
/*
Output:
$ gcc 28.c && ./a.out 
Current msg queue file permission : 644
Updating msg queue permission to 0600
Updated msg queue file permission : 600
*/