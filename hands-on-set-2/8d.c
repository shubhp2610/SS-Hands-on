/*
============================================================================
Name : 8d.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : 8. Write a separate program using signal system call to catch the following signals.
                 d. SIGALRM (use alarm system call)
Date: 15th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signal_handeler(int sig) {
    printf("SIGALRM caught!\n");
    exit(0);
}
int main() {

    if (signal(SIGALRM, signal_handeler) == SIG_ERR) {
        perror("signal");
        return 1;
    }

    printf("Throwing SIGALARM in 2 seconds....\n");
    alarm(2);
    
    for(int i =0;i<2;i++){
        printf("sec %d\n",i+1);
        sleep(1);
    }
    return 0;
}
/*
Output:

$ ./a.out 
Throwing SIGALARM in 2 seconds....
sec 1
sec 2
SIGALRM caught!

*/