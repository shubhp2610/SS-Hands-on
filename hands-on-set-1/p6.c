/*
Name: Shubh Sanjaykumar Patel
Roll No.: MT2024148
Problem No.: 6
Problem statement: Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
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
