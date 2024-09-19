/*
============================================================================
Name : 19.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : 19. Create a FIFO file by
                d. mknod system call
                e. mkfifo library function
Date: 19th Sept, 2024.
============================================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 

int main() {

    if (mkfifo("fifo1", 0644) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
    printf("FIFO created using mkfifo\n");
    
    if (mknod("fifo2", S_IFIFO | 0644, 0) == -1) {
        perror("mknod");
        exit(EXIT_FAILURE);
    }

    printf("FIFO created using mknod\n");

    return 0;
}
/*
Output:
$ gcc 19de.c && ./a.out 
FIFO created using mkfifo
FIFO created using mknod

running again
$ gcc 19de.c && ./a.out 
mkfifo: File exists
*/
