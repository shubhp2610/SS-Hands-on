/*
============================================================================
Name : 10c.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a separate program using sigaction system call to catch the following signals.
                c. SIGFPE
Date: 20th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum) {
    printf("Received SIGFPE: Floating-point exception\n");
    exit(0); 
}
int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    printf("Handeling SIGFPE. Causing divide by zero.\n");
    if (sigaction(SIGFPE, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }
    1/0;
    return 0;
}

/*
Output
$ gcc 10c.c && ./a.out
Handeling SIGFPE. Causing divide by zero.

*/
