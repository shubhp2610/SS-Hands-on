/*
============================================================================
Name : 32d.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to implement semaphore to protect any critical section.
                d. remove the created semaphore
Date: 21th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
    key_t key = ftok(".", 2);
    int semid = semget(key, 0, IPC_CREAT | 0644);
    if (semid == -1) {
        perror("semget");
        return 1;
    }
    if(semctl(semid,0,IPC_RMID)==-1){
        perror("semctl IPC_RMID");
        return 1;
    }
    printf("Semaphore deleted!\n");
    return 0;
}


/*
Output:
$ gcc 32b.c && ./a.out 
Waiting for semaphore!
Access granted!
Previous message : 
Enter message to write into shared memory :message one
Messsage written
Press enter to unlock
Released access!

$ gcc 32b.c && ./a.out 
Waiting for semaphore!
Access granted!
Previous message : message one
Enter message to write into shared memory :message two
Messsage written
Press enter to unlock
Released access!


*/