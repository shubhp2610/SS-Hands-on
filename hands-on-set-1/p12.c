/*
============================================================================
Name : p12.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 20th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

void main(int argc, char *argv[]){
	// checking for correct input
	if(argc<2){
		printf("Error: please specify a file name!\n");
		printf("Usage: %s <filename>\n",argv[0]);
		return;
	}
	int fd = open(argv[1], O_RDWR);
	if(fd==-1){
		perror("Error opening file in O_RDONLY mode");
		return;
	}
	//fetching file access mode
	int flags =  fcntl(fd,F_GETFL);
	if (flags == -1) {
        perror("fcntl error");
        close(fd);
        return;
    }
	// checking and printing the flag
    printf("File opening mode: ");
    if (flags & O_RDONLY) {
        printf("O_RDONLY\n");
    }
    if (flags & O_WRONLY) {
        printf("O_WRONLY\n");
    }
    if (flags & O_RDWR) {
        printf("O_RDWR\n");
    }
	if (flags & O_CREAT) {
        printf("O_CREAT\n");
    }
    if (flags & O_EXCL) {
        printf("O_EXCL\n");
    }
    close(fd);
    return;
}

/*
Output:
File opening mode: O_RDWR
*/