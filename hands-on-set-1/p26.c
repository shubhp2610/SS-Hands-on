/*
============================================================================
Name : p26.c
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
