/*
Name: Shubh Sanjaykumar Patel
Roll No.: MT2024148
Problem No.: 3
Problem statement: Write a program to create a file and print the file descriptor value. Use creat ( ) system call.
*/
#include<stdio.h>
#include <fcntl.h>
#include <errno.h>

void main(void){
	const char *pathname = "newFile.txt";
	int fd = creat(pathname, S_IRWXU);
	if(fd==-1){
		perror("Error creating file.");
	}
	printf("File created with fd = %d",fd);
}
