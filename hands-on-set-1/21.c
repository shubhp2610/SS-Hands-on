/*
============================================================================
Name : 21.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program, call fork and print the parent and child process id.
Date: 26th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
void main(){
    int child_id =  fork();
    if(child_id == 0){
        printf("\n--------- CHILD ---------\n");
        printf("child process id : %d\n",getpid());
        printf("parent process id : %d\n",getppid());
    }else{
        printf("\n--------- PARENT ---------\n");
        printf("child process id : %d\n",child_id);
        printf("parent process id : %d\n",getpid());
    }
}
/*
Output:
$ ./a.out 

--------- PARENT ---------
child process id : 33327
parent process id : 33326

--------- CHILD ---------
child process id : 33327
parent process id : 33326
*/