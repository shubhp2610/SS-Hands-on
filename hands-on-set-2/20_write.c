/*
============================================================================
Name : 20_write.c
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

int main() {
    
    int fd = open("fifo",O_WRONLY);
    if(fd==-1){
        perror("open");
        return 1;
    }
   
    char buffer[200];
    printf("Enter text for FIFO : ");
    scanf("%[^\n]", buffer);
    write(fd,buffer,sizeof(buffer));
    printf("Written to FIFO!\n");
    return 0;
}
/*
Output:
$ gcc 20_write.c && ./a.out 
Enter text for FIFO : hello there
Written to FIFO!
*/
