/*
============================================================================
Name : p27b.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to execute ls -Rl by the following system calls.
              b. execlp
Date: 30th Aug, 2024.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
int main(){
    if(execlp("/bin/ls","-R","-l",(char *)NULL)==-1){
        perror("execlp error");
        return 1;
    } 
    return 0;
}