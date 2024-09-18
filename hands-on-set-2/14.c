/*
============================================================================
Name : 14.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 18th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
int main() {
    int fd[2];
    char buffer[200];
    if(pipe(fd)==-1){
        perror("pipe");
        return 1;
    }
    int bytes_written = write(fd[1], "MY DATA\n", 8);
    read(fd[0], buffer, bytes_written);
    printf("Reading from pipe: %s\n", buffer);
    return 0;
}

/*
Output:
$ ./a.out 
Reading from pipe: MY DATA
*/
