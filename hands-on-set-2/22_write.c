/*
============================================================================
Name : 22_write.c
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
#include <sys/select.h>
int main() {
    
    int fd = open("fifo1",O_WRONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    char buffer[200];
    printf("Enter text for FIFO : ");
    scanf("%[^\n]", buffer);
    write(fd,buffer,sizeof(buffer));
    printf("Written to FIFO!\n");
    close(fd); 
    return 0;
}
/*
Output:
$ gcc 22_write.c && ./a.out 
Enter text for FIFO : helllo
Written to FIFO!
*/
