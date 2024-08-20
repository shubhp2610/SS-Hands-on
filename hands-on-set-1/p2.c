/*
Name: Shubh Sanjaykumar Patel
Roll No.: MT2024148
Problem No.: 2
Problem statement: Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
*/
#include<stdio.h>
void main(void){
for(;;);
}

/* Executed as followed:
gcc p2.c -o p2
./p2 &

output: [1] 9860
explored /proc/9860 process directory 
*/