/*
============================================================================
Name : 26.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to execute an executable program.
                a. use some executable program
                b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
int main(int argc, char *argv[]) {
    if(argc<3){
        printf("Error: please specify a file name and a single argument for it!\n");
        printf("Usage: %s <filename> <argument>\n",argv[0]);
        return 1;
    }
    int status = execl(argv[1], argv[1], argv[2], (char *)NULL);
    if(status==-1){
        perror("execl error");
        return 1;
    }
    return 0;
}

/*
Output:
$ ./a.out p9 9.c
I-node number:             3541746
Hard link count:           1
UID:                       1000
GID:                       1000
File size:                 2099 bytes
I/O block size:            4096 bytes
Blocks allocated:          8
Time of last access:       Sat Aug 31 14:01:58 2024
Time of last modification: Sat Aug 31 13:35:05 2024
Time of Last change:       Sat Aug 31 13:35:05 2024
*/