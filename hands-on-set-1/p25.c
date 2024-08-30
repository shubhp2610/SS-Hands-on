/*
============================================================================
Name : p25.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int a,b,c;
    if(!(a=fork())){
        sleep(3);
        printf("Child Process 1 exited!\n");
    }else{
        if(!(b=fork())){
        sleep(5);
        printf("Child Process 2 exited!\n");
        }else{
            if(!(c=fork())){
            sleep(10);
            printf("Child Process 3 exited!\n");
            }else{
                printf("Parent waiting for child 2.\n");
                waitpid(b,NULL,0);
                printf("Parent exited!\n");
            }
        }
    }
    return 0;
}

/*
Output:
Parent waiting for child 2.
Child Process 1 exited!
Child Process 2 exited!
Parent exited!
Child Process 3 exited!
*/