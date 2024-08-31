/*
============================================================================
Name : 10.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
				a. check the return value of lseek
				b. open the file with od and check the empty spaces in between the data. 
Date: 20th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
void main(int argc, char * argv[]) {
	// checking for correct input
	if(argc<2){
		printf("Error: please specify a file name!\n");
		printf("Usage: ./p10 <filename>\n");
		return;
	}
	int fd = open(argv[1],O_RDWR);
	if(fd==-1){	
		perror("Error opening file in O_RDONLY mode");
		return;
	}
	//each character is of size 1 byte
	char buff[10] = {'S','H','U','B','H',' ','1','4','8','\0'};
	ssize_t written =  write(fd, &buff, 10);
	printf("written %ld bytes\n",written);
	off_t seeked =  lseek(fd, 10, SEEK_CUR);
	printf("seeked %ld bytes\n",seeked);
	written =  write(fd, &buff, 10);
	printf("written %ld bytes\n",written);
	close(fd);
	return;
}


/*
Output:
$ ./p10 test
written 10 bytes
seeked 20 bytes
written 10 bytes

File content checked using od
$ od -c test 
0000000   S   H   U   B   H       1   4   8  \0  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   S   H   U   B   H       1   4   8  \0
0000036
*/