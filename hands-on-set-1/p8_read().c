/*
Name: Shubh Sanjaykumar Patel
Roll No.: MT2024148
Problem No.: 8
Problem statement: Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
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
    int fd = open(pathname, O_RDONLY);
    if(fd==-1){
        perror("Error opening file in O_RDONLY mode");
        return;
    }
    // initializing buffer
    int BUFFER_SIZE = 500;
    char mybuffer[BUFFER_SIZE];
    int charPointer = 0;
    // reading character by character
    while((read(fd,&mybuffer[charPointer],1))>0){
        if(mybuffer[charPointer]=='\n' || charPointer == BUFFER_SIZE-1 ){
            mybuffer[charPointer+1]='\0';
            printf("%s",mybuffer);
            charPointer=0;
        }else{
            charPointer++;
        }
    }
    if(charPointer>0){
        mybuffer[charPointer+1]='\0';
        printf("%s",mybuffer);
    }
    close(fd);
    return;
}