/*
============================================================================
Name : p22.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 26th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
int main(){
    char *path = "temp";
    int fd = open(path, O_RDWR | O_APPEND | O_CREAT, 0644);
    if(fd==-1){
		perror("Error opening file.");
		return 1;
	}
    int child_id = fork();
    if (child_id == 0) {
        char buff[] = "CHILD\n";
        write(fd, buff, sizeof(buff) - 1);
    } else {
        char buff[] = "PARENT\n";
        write(fd, buff, sizeof(buff) - 1);
    }
    close(fd);
    return 0;
}

/*
Output file contents:
PARENT
CHILD

Output can vary, it depends on scheduler. If child run first it will write first.
*/