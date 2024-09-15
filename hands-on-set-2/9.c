/*
============================================================================
Name : 9.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.
Date: 12th Sept, 2024.
============================================================================
*/
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include <unistd.h>

void singla_handler(int sig) {
    printf("SIGINT interupt recieved. Signla number: %d\n", sig);
    exit(0);
}
int main(){
    // Ignoring the signal
    signal(SIGINT,SIG_IGN);
    printf("Ignoring SIGINT singal\n");
    sleep(5);
    printf("Ignoring phase completed.\n");
    
    // custom handeler to catch signal
    signal(SIGINT,singla_handler);
    printf("Handeling SIGINT singal\n");
    sleep(5);
    printf("SIGINT not recieved in 5 seconds.\n");
    
    return 0;
}

/*
Output:
----------- If SIGINT signaled ------------
Ignoring SIGINT singal
^C^C^C^C^C^C^C^CSIGINT not recieved in 5 seconds.
Handeling SIGINT singal
^CSIGINT interup recieved. Signla number: 2

----------- No singal provided ---------------
Ignoring SIGINT singal
SIGINT not recieved in 5 seconds.
Handeling SIGINT singal
SIGINT not recieved in 5 seconds.
*/