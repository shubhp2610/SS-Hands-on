/*
============================================================================
Name : p27d.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to execute ls -Rl by the following system calls.
              d. execv
Date: 30th Aug, 2024.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
int main(){
    char *arg[] = {"ls","-R", "-l", NULL};
    if(execv("/bin/ls",arg)==-1){
        perror("execv error");
        return 1;
    } 
    return 0;
}