/*
============================================================================
Name : 15.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a simple program to send some data from parent to the child process.
Date: 18th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
int main() {
    int fd[2];
    if(pipe(fd)==-1){
        perror("pipe");
        return 1;
    }
    char buffer[200];
    if (!fork()) {
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("Message from parent: %s\n", buffer);
    }
    else {
        close(fd[0]);
        printf("Message for child: ");
        scanf("%[^\n]", buffer);
        write(fd[1], buffer, sizeof(buffer));
    }
    wait(0);
    return 0;
}

/*
Output:
$ ./a.out 
Message for child: hello child process
Message from parent: hello child process
*/
