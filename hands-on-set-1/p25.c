/*
Name: Shubh Sanjaykumar Patel
Roll No.: MT2024148
Problem No.: 25
Problem statement: Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int child1 = fork();
    int child2 = fork();
    int child3 = fork();
    if()
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