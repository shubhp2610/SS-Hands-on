/*
============================================================================
Name : 30b.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : 30. Write a program to create a shared memory.
                b. attach with O_RDONLY and check whether you are able to overwrite.
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
    printf("Enter message to add to shared memory : ");
    scanf(" %[^\n]",data);
    printf("Message added to shared memory!\n");
    printf("Current memory content : %s",data);
    return 0;
}
/*
Output:
$ gcc 30b.c && ./a.out 
Enter message to add to shared memory : new value
Segmentation fault (core dumped)
   
*/