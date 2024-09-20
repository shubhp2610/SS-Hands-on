/*
============================================================================
Name : 10a.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a separate program using sigaction system call to catch the following signals.
                a. SIGSEGV
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum) {
    printf("Received SIGSEGV : Segmentation Fault\n");
    exit(0);
}
int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        return 2;
    }
    printf("Triggering SIGSEGV by accessing invalid memory address\n");
    char *s= "ac";
    *(s + 1) = 'b';
    return 0;
}

/*
Output
$ gcc 10a.c && ./a.out 
Triggering SIGSEGV by accessing invalid memory address
Received SIGSEGV : Segmentation Fault

*/
