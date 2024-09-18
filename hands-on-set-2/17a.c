/*
============================================================================
Name : 17a.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to execute ls -l | wc.
              a. use dup
Date: 18th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
int main() {
    int fd1[2];
    if(pipe(fd1)==-1){
        perror("pipe");
        return 1;
    }
    if (!fork()) {
        close(1);
        dup(fd1[1]);
        close(fd1[0]);
        execlp("ls", "ls", "-Rl", (char*) NULL);
    }
    else {
        close(0);
        dup(fd1[0]);
        close(fd1[1]);
        execlp("wc", "wc", (char*) NULL);
    }
    wait(0);
    return 0;
}
/*
Output:
$ ./a.out 
     34     291    1663
*/
