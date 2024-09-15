/*
============================================================================
Name : 8b.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : 8. Write a separate program using signal system call to catch the following signals.
                 b. SIGINT
Date: 15th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void signal_handeler(int sig) {
    printf("SIGINT caught!\n");
    exit(0);
}
int main() {
    
    if (signal(SIGINT, signal_handeler) == SIG_ERR) {
        perror("signal");
        return 1;
    }

    printf("Handeling SIGINT singal. Press Ctrl+c ...\n");
    sleep(5);
    printf("SIGINT not recieved in 5 seconds.\n");

    return 0;
}
/*
Output:

$ ./a.out 
Handeling SIGINT singal. Press Ctrl+c ...
^CSIGINT caught!

$ ./a.out 
Handeling SIGINT singal. Press Ctrl+c ...
SIGINT not recieved in 5 seconds.
*/