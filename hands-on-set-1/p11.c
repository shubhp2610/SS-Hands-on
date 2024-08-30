/*
============================================================================
Name : p11.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : 11. Write a program to open a file, duplicate the file descriptor and append the file
              with both the descriptors and check whether the file is updated properly or not.
              a. use dup
              b. use dup2
              c. use fcntl
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

void write_to_file(int fd, const char *text) {
    if (write(fd, text, strlen(text)) == -1) {
        perror("write error");
    }
}

int main() {
    int fd1, fd2, fd3=10, fd4;
    const char *filename = "example.txt";
    const char *text1 = "open\n";
    const char *text2 = "dup\n";
    const char *text3 = "dup2\n";
    const char *text4 = "fcntl\n";

    //opening the file in append mode
    fd1 = open(filename, O_WRONLY | O_APPEND);
    if (fd1 == -1) {
        perror("open error"); return 1;
    }
    //using dup
    fd2 = dup(fd1);
    if (fd2 == -1) {
        perror("dup error"); close(fd1); return 1;
    }
    //using dup2
    fd3 = dup2(fd1, fd3);
    if (fd3 == -1) {
        perror("dup2 error"); close(fd1); close(fd2); return 1;
    }
    //using fcntl
    fd4 = fcntl(fd1, F_DUPFD);
    if (fd4 == -1) {
        perror("fcntl error");
        close(fd1); close(fd2); close(fd3);
        return 1;
    }
    //writing to file
    write_to_file(fd1, text1);
    write_to_file(fd2, text2);
    write_to_file(fd3, text3);
    write_to_file(fd4, text4);
    //closing all file descriptors
    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);

    printf("File written successfully.\n");
    return 0;
}
