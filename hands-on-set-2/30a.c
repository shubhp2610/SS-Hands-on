/*
============================================================================
Name : 30a.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : 30. Write a program to create a shared memory.
                a. write some data to the shared memory
Date: 19th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
int main() {

    key_t shm_key = ftok(".",2);
    int shm_id = shmget(shm_key,200, IPC_CREAT | 0644);
    char *data;
    data = shmat(shm_id, (void *)0, 0);
    if (data == (void *) -1){
        perror("shmat");
        return 1;
    }
    printf("Enter message to add to shared memory : ");
    scanf(" %[^\n]",data);
    printf("Message added to shared memory!\n");
    return 0;
}
/*
Output:
$ gcc 30.c && ./a.out 
Enter message to add to shared memory : helllllo
Message added to shared memory!

$ ipcs -m
------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status               
0x02051e90 30         ubuntu     644        200        1    
*/