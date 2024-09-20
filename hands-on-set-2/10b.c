/*
============================================================================
Name : 10b.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a separate program using sigaction system call to catch the following signals.
                b. SIGINT
Date: 20th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum) {
    printf(" Received SIGINT\n"); 
    exit(0);
}
int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    printf("Handeling SIGINT. Press ctrl+c.\n");
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }
    pause();
    return 0;
}

/*
Output
$ gcc 10b.c && ./a.out 
Handeling SIGINT. Press ctrl+c.
^C Received SIGINT

*/
