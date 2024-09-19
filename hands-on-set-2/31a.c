/*
============================================================================
Name : 31a.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to create a semaphore and initialize value to the semaphore.
                a. create a binary semaphore
Date: 19th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

int main() {
    key_t key = ftok(".", 2);

    // creating a semaphore set with 1 semaphore
    int semid = semget(key, 1, IPC_CREAT | 0644);

    if (semid == -1) {
        perror("semget");
        return 1;
    }

    // initialized with 1 for binary semaphore
    if (semctl(semid, 0, SETVAL, 1) == -1) {
        perror("semctl");
        return 1;
    }

    printf("Binary semaphore created and initialized to 1.\n");
    return 0;
}


/*
Output:
$ gcc 31a.c && ./a.out 
Binary semaphore created and initialized to 1.

$ ipcs -s
------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x02051e90 1          ubuntu     644        1 
*/