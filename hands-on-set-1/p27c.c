/*
============================================================================
Name : p27c.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to execute ls -Rl by the following system calls.
              c. execle
Date: 30th Aug, 2024.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
extern char **environ;
int main(){
    if(execle("/bin/ls","ls","-R","-l", (char *) NULL,environ)==-1){
        perror("execle error");
        return 1;
    } 
    return 0;
}