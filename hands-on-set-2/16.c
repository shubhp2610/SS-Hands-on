/*
============================================================================
Name : 16.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to send and receive data from parent to child vice versa. Use two way
communication.
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
    char buffer1[200];
    char buffer2[200];
    if (!fork()) {
        close(fd1[0]); close(fd2[1]);
        printf("Message for parent: ");
        scanf("%[^\n]", buffer1);
        write(fd1[1], buffer1, sizeof(buffer1));
        read(fd2[0], buffer2, sizeof(buffer2));
        printf("Message from parent: %s\n", buffer2);
    }
    else {
        close(fd1[1]); close(fd2[0]);
        read(fd1[0], buffer1, sizeof(buffer1));
        printf("Message from child: %s\n", buffer1);
        printf("Message for child: ");
        scanf("%[^\n]", buffer2);
        write(fd2[1], buffer2, sizeof(buffer2));
    }
    wait(0);
    return 0;
}

/*
Output:
$ ./a.out 
Message for parent: CHILD SENDING
Message from child: CHILD SENDING
Message for child: PARENT SENDING
Message from parent: PARENT SENDING
*/
