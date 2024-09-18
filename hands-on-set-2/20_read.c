/*
============================================================================
Name : 20_read.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 18th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
int main() {
    
    int fd = open("fifo",O_RDONLY);
    if(fd==-1){
        perror("open");
        return 1;
    }
   
    char buffer[200];
    read(fd,buffer,sizeof(buffer));
    printf("Read from FIFO : %s\n",buffer);
    return 0;
}
/*
Output:
$ gcc 20_read.c && ./a.out
Read from FIFO : hello there
*/
