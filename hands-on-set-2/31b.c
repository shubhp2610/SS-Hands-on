/*
============================================================================
Name : 31b.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to create a semaphore and initialize value to the semaphore.
                b. create a counting semaphore
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

    // initialized with 6 for counting semaphore
    if (semctl(semid, 0, SETVAL, 6) == -1) {
        perror("semctl");
        return 1;
    }

    printf("Counting semaphore created and initialized to 6.\n");
    return 0;
}


/*
Output:
$ gcc 31b.c && ./a.out 
Counting semaphore created and initialized to 6.

$ ipcs -s
------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x02051e90 2          ubuntu     644        1
*/