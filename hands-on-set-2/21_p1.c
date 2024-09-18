/*
============================================================================
Name : 21_p1.c
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
#include <sys/wait.h>
int main() {
    
    int fd1 = open("fifo1",O_WRONLY);
    int fd2 = open("fifo2",O_RDONLY);
    if(fd1==-1 || fd2==-1){
        perror("open");
        return 1;
    }
   
    char buffer[200];
    
    printf("Enter text for P2 : ");
    scanf("%[^\n]", buffer);
    write(fd1,buffer,sizeof(buffer));
    printf("Written to FIFO!\n");

    printf("Waiting for P2\n");
    read(fd2,buffer,sizeof(buffer));
    printf("Read from FIFO : %s\n",buffer);
    return 0;
}
/*
Output:
$ gcc 21_p1.c && ./a.out 
Enter text for P2 : msg from p1
Written to FIFO!
Waiting for P2
Read from FIFO : msg from p2
*/
