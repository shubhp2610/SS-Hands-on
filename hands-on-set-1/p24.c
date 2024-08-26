/*
Name: Shubh Sanjaykumar Patel
Roll No.: MT2024148
Problem No.: 24
Problem statement: Write a program to create an orphan process.
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    if (!fork()) {
        printf("CHILD PROCESS - parent before orphan = %d\n", getppid());
        sleep(2);
        printf("CHILD PROCESS - parent after orphan = %d\n", getppid());
    }
    else {
        printf("PARENT PROCESS ID %d\n---- Parent Exited! ----\n", getpid());
        exit(0);
    }
}

/*
Output:
PARENT PROCESS ID 26842
---- Parent Exited! ----
CHILD PROCESS - parent before orphan = 26842
CHILD PROCESS - parent after orphan = 1736

Process with 1736 id is systemd.
*/