/*
============================================================================
Name : 32b.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to implement semaphore to protect any critical section.
                b. protect shared memory from concurrent write access
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
    int semid = semget(key, 1, O_CREAT | 0644);
    if (semid == -1) {
        perror("semget");
        return 1;
    }
    struct sembuf sop;
    sop.sem_num = 0;
    sop.sem_op = -1;
    sop.sem_flg = 0;
    printf("Waiting for semaphore!\n");
    if (semop(semid, &sop, 1) == -1) {
        perror("semop");
        exit(1);
    }
    printf("Access granted!\n");
    int shmid = shmget(key,200,IPC_CREAT | 0644);
    char *data;
    data = shmat(shmid, (void *)0, 0);
    printf("Previous message : %s\n",data);
    printf("Enter message to write into shared memory :");
    scanf(" %[^\n]",data);
    printf("Messsage written\nPress enter to unlock\n");
    getchar();
    getchar();
    shmdt(data);
    sop.sem_op=1;
    if (semop(semid, &sop, 1) == -1) {
        perror("semop");
        exit(1);
    }
    printf("Released access!\n");
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