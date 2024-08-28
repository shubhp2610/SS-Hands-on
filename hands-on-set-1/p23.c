/*
Name: Shubh Sanjaykumar Patel
Roll No.: MT2024148
Problem No.: 23
Problem statement: Write a program to create a Zombie state of the running program.
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    if (!fork()) {
        printf("CHILD PROCESS ID %d\n---- Child Exited! ----\n", getpid());
        exit(0);   
    }
    else {
        printf("PARENT PROCESS ID %d\n", getpid());
        printf("Parent going to sleep for 10 seconds.\n");
        sleep(10);
        wait(NULL);
        printf("Child process collected by parent." );
        exit(0);
    }
}

/*
Output:
PARENT PROCESS ID 13090
Parent going to sleep for 10 seconds.
CHILD PROCESS ID 13091
---- Child Exited! ----
Child process collected by parent.

$ ps ux
ubuntu     13090  0.0  0.0   2616  1280 pts/2    S+   18:21   0:00 ./p23
ubuntu     13091  0.0  0.0      0     0 pts/2    Z+   18:21   0:00 [p23] <defunct>
The Z+ show the status of child process as zombie during that 10 second timeframe. 
Later on it is collected by the parent.
*/