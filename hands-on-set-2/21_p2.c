/*
============================================================================
Name : 21_p2.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 18th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int main() {
    
    int fd1 = open("fifo1",O_RDONLY);
    int fd2 = open("fifo2",O_WRONLY);
    if(fd1==-1 || fd2==-1){
        perror("open");
        return 1;
    }
   
    char buffer[200];
    printf("Waiting for P1\n");
    read(fd1,buffer,sizeof(buffer));
    printf("Read from FIFO : %s\n",buffer);

    printf("Enter text for P1 : ");
    scanf("%[^\n]", buffer);
    write(fd2,buffer,sizeof(buffer));
    printf("Written to FIFO!\n");

    return 0;
}
/*
Output:
$ gcc 21_p2.c && ./a.out
Waiting for P1
Read from FIFO : msg from p1
Enter text for P1 : msg from p2
Written to FIFO!
*/
