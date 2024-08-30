/*
============================================================================
Name : p4.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 20th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
    const char *filename = "p3.c"; // opening previous code
    int fd1, fd2;

    fd1 = open(filename, O_RDWR);
    if (fd1 == -1) {
        perror("Error opening file in O_RDWR mode");
        return 0;
    }
    printf("File opened successfully in O_RDWR mode with fd = %d\n",fd1);
    close(fd1);
    
    fd2 = open(filename, O_RDWR | O_CREAT | O_EXCL,0777);
    if (fd2 == -1) {
        perror("Error opening file in O_RDWR | O_EXCL mode.");
        // the error is caused due to the flags O_CREAT and O_EXCL. O_EXCL flag prevents creation of new file if it already exist.
        // Hence, when used with O_CREAT flag it will throw error when file already exist. Without O_CREAT it will be ignored.
        return 0;
    }
    printf("File opened successfully in O_RDWR | O_EXCL mode with fd = %d\n",fd2);
    close(fd2);
    
    return 0;
}
