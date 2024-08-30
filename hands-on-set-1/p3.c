/*
============================================================================
Name : p3.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to create a file and print the file descriptor value. Use creat () system call.
Date: 20th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include <fcntl.h>
#include <errno.h>

void main(void){
	const char *pathname = "newFile.txt";
	int fd = creat(pathname, 0644);
	if(fd==-1){
		perror("Error creating file.");
	}
	printf("File created with fd = %d",fd);
}
