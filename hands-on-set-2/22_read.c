/*
============================================================================
Name : 22_read.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 18th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/select.h>
#include <sys/time.h>
int main() {
    
    int fd = open("fifo1",O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    struct timeval tv;
    tv.tv_sec = 10;
    tv.tv_usec = 0;
    fd_set rdfd;
    FD_ZERO(&rdfd);
    FD_SET(fd,&rdfd);
    printf("Waiting for data in FIFO!\n");
    int change = select(fd+1, &rdfd, NULL, NULL, &tv);
    if(change == -1){
        perror("select");
        return 1;
    }else if (change == 0){
        printf("No data in FIFO with in 10 seconds.\n");
    }else{
        char buffer[200];
        read(fd,buffer,sizeof(buffer));
        printf("Read from FIFO : %s\n",buffer);
    }
    close(fd);
    return 0;
}
/*
Output:

$ gcc 22_read.c && ./a.out 
Waiting for data in FIFO!
Read from FIFO : helllo

$ gcc 22_read.c && ./a.out 
Waiting for data in FIFO!
No data in FIFO with in 10 seconds.
*/
