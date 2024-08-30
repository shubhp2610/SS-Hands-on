/*
============================================================================
Name : p6.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
Date: 20th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include <unistd.h>
void main(void){
    char buf[120];
    printf("Enter your name below: \n");
    //reading from standard input
    int slen = read(0,buf,120);
    //writing to standard output
    write(1,buf,slen);
}
