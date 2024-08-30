/*
============================================================================
Name : p8_fgsets().c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 20th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
void main(int argc, char **argv){
    // checking for correct input
    if(argc<2){
        printf("Error: please specify a file name!\n");
        printf("Usage: ./p8 <filename>\n");
        return;
    }
    const char *pathname = argv[1];
    // opening file as read only
    FILE *file = fopen(pathname, "r");
    if(file==NULL){
        perror("Error opening file in O_RDONLY mode");
        return;
    }
    // initializing buffer
    int BUFFER_SIZE = 500;
    char mybuffer[BUFFER_SIZE];
    // reading line by line
    while (fgets(mybuffer, sizeof(mybuffer), file) != NULL) {
        printf("%s", mybuffer);
    }
    fclose(file);
    return;
}