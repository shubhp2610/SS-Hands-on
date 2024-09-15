/*
============================================================================
Name : 11.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 12th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    struct sigaction sigac;

    sigac.sa_handler = SIG_IGN;
    sigac.sa_flags = 0;        
    sigemptyset(&sigac.sa_mask);

    if (sigaction(SIGINT, &sigac, NULL) == -1) {
        perror("sigaction error");
        return 1;
    }
    
    printf("Ignoring SIGINT for next 5 seconds.\n");
    sleep(5);
    sigac.sa_handler = SIG_DFL;
    if (sigaction(SIGINT, &sigac, NULL) == -1) {
        perror("sigaction error");
        return 1;
    }

    printf("\nSIGINT action reset to default for next 5 seconds.\n");
    sleep(5);

    return 0;
}

/*
Output:

Ignoring SIGINT for next 5 seconds.
^C^C^C^C^C^C
SIGINT action reset to default for next 5 seconds.
^C

*/