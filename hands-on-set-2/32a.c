/*
============================================================================
Name : 32a.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to implement semaphore to protect any critical section.
                a. rewrite the ticket number creation program using semaphore
Date: 21th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
    key_t key = ftok(".", 2);
    int semid = semget(key, 1, 0); 
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
    int fd = open("ticket",O_RDWR);
    struct ticket{
        int number;
    } tk;
    read(fd,&tk,sizeof(tk));
    tk.number++;
    lseek(fd,0,SEEK_SET);
    write(fd,&tk,sizeof(tk));
    printf("Ticker number booked : %d\nPress enter to unlock\n",tk.number);
    getchar();
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
$ gcc 32a.c && ./a.out 
Waiting for semaphore!
Access granted!
Ticker number booked : 1
Press enter to unlock
Released access!

$ gcc 32a.c && ./a.out 
Waiting for semaphore!
Access granted!
Ticker number booked : 2
Press enter to unlock
Released access!

*/