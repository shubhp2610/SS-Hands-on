/*
============================================================================
Name : 32a_init.c
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
    //creating semaphore
    key_t key = ftok(".", 2);
    int semid = semget(key, 1, IPC_CREAT | 0644);
    semctl(semid, 0, SETVAL, 1);

    //creating file
    int fd = open("ticket", O_CREAT | O_RDWR, 0644);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    struct ticket{
        int number;
    } tk;
    tk.number = 0;
    write(fd, &tk, sizeof(tk));
    close(fd);
    return 0;
}
