/*
============================================================================
Name : 8c.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : 8. Write a separate program using signal system call to catch the following signals.
                 b. SIGFPE
Date: 15th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signal_handeler(int sig) {
    printf("SIGFPE: Floating-point exception caught!\n");
    exit(0);
}
int main() {
    
    if (signal(SIGFPE, signal_handeler) == SIG_ERR) {
        perror("signal");
        return 1;
    }

    int i = 1/0;

    return 0;
}
/*
Output:

$ ./a.out 
SIGFPE: Floating-point exception caught!

*/