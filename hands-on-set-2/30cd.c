/*
============================================================================
Name : 30cd.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : 30. Write a program to create a shared memory.
                c. detach the shared memory
                d. remove the shared memory
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
    data = shmat(shm_id, (void *)0, SHM_RDONLY);
    if (data == (void *) -1){
        perror("shmat");
        return 1;
    }
    shmdt(data);
    printf("Shared memory detached!\n");
    shmctl(shm_id, IPC_RMID,NULL);
    printf("Shared memory deleted!\n");
    return 0;
}
/*
Output:
$ gcc 30cd.c && ./a.out 
Shared memory detached!
Shared memory deleted!

*/