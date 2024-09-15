/*
============================================================================
Name : 8a.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : 8. Write a separate program using signal system call to catch the following signals.
                 a. SIGSEGV
Date: 15th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void signal_handeler(int sig) {
    printf("SIGSEGV : Segmentation Fault caught!\n");
    exit(0);
}
int main() {
    
    if (signal(SIGSEGV, signal_handeler) == SIG_ERR) {
        perror("signal");
        return 1;
    }

    int *p = NULL;
    *p = 1;

    return 0;
}
/*
Output:
$ ./a.out 
SIGSEGV : Segmentation Fault caught!
*/