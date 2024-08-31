/*
============================================================================
Name : 2.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 20th Aug, 2024.
============================================================================
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