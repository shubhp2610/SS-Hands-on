/*
============================================================================
Name : 18.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to find out total number of directories on the pwd. execute ls -l | grep ^d | wc ? Use only dup2.
Date: 18th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
int main() {
    int fd1[2], fd2[2];
    if(pipe(fd1)==-1 || pipe(fd2)==-1){
        perror("pipe");
        return 1;
    }
    if (!fork()) {
        dup2(fd1[1], 1);
        close(fd1[0]);
        close(fd2[0]);
        close(fd2[1]);
        execlp("ls", "ls", "-Rl", (char*) NULL);
    }
    else {
        if (!fork()) {
            dup2(fd2[1], 1);
            dup2(fd1[0], 0);
            close(fd1[1]);
            close(fd2[0]);
            execlp("grep", "grep", "^d", (char*) NULL);
        }
        else {
            dup2(fd2[0], 0);
            close(fd2[1]);
            close(fd1[0]);
            close(fd1[1]);
            execlp("wc", "wc", (char*) NULL);
        }
    }
    wait(0);
    return 0;
}
/*
Output:
$ ./a.out 
     20     180    1121
*/
