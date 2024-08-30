/*
============================================================================
Name : p27a.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to execute ls -Rl by the following system calls.
              a. execl
Date: 30th Aug, 2024.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
int main(){
    if(execl("/bin/ls","ls","-R","-l",(char *)NULL)==-1){
        perror("execl error");
        return 1;
    } 
    return 0;
}