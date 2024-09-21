/*
============================================================================
Name : 32c.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to implement semaphore to protect any critical section.
                c. protect multiple pseudo resources ( may be two) using counting semaphore
Date: 21th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <sys/wait.h>
#define NUM_RESOURCES 2
#define NUM_PROCESSES 5

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int semid;

void init_semaphore() {
    union semun arg;
    unsigned short values[NUM_RESOURCES] = {2, 2}; // Initial values for two resources
    int key = ftok(".",4);
    semid = semget(key, NUM_RESOURCES, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    arg.array = values;
    if (semctl(semid, 0, SETALL, arg) == -1) {
        perror("semctl");
        exit(1);
    }
}

void acquire_resource(int resource_id) {
    struct sembuf sb;
    sb.sem_num = resource_id;
    sb.sem_op = -1;
    sb.sem_flg = 0;
    printf("WAIT : Process %d - resource %d\n", getpid(), resource_id);
    if (semop(semid, &sb, 1) == -1) {
        perror("semop");
        exit(1);
    }
    printf("ACQUIRED : Process %d - resource %d\n", getpid(), resource_id);
}

void release_resource(int resource_id) {
    struct sembuf sb;
    sb.sem_num = resource_id;
    sb.sem_op = 1;
    sb.sem_flg = 0;
    
        if (semop(semid, &sb, 1) == -1) {
        perror("semop");
        exit(1);
    }
    printf("RELEASED : Process %d - resource %d\n", getpid(), resource_id);
}

void process_function(int process_id) {
    int resource_id = process_id % NUM_RESOURCES;
    
    acquire_resource(resource_id);
    sleep(2);
    release_resource(resource_id);
}
int main() {
    init_semaphore();

    for (int i = 0; i < NUM_PROCESSES; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            process_function(i);
            exit(0);
        }
    }
    for (int i = 0; i < NUM_PROCESSES; i++) {
        wait(NULL);
    }
    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl (IPC_RMID)");
        exit(1);
    }

    return 0;
}

/*
Output:
$ gcc 32c.c && ./a.out 
WAIT : Process 57342 - resource 0
ACQUIRED : Process 57342 - resource 0
WAIT : Process 57343 - resource 1
ACQUIRED : Process 57343 - resource 1
WAIT : Process 57344 - resource 0
ACQUIRED : Process 57344 - resource 0
WAIT : Process 57345 - resource 1
ACQUIRED : Process 57345 - resource 1
WAIT : Process 57346 - resource 0
RELEASED : Process 57342 - resource 0
ACQUIRED : Process 57346 - resource 0
RELEASED : Process 57343 - resource 1
RELEASED : Process 57344 - resource 0
RELEASED : Process 57345 - resource 1
RELEASED : Process 57346 - resource 0

*/