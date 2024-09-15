/*
============================================================================
Name : 8f.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : 8. Write a separate program using signal system call to catch the following signals.
                 e. SIGVTALRM (use setitimer system call)
Date: 15th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void signal_handeler(int sig) {
    printf("SIGVTALRM caught!\n");
    exit(0);
}
int main() {
    if (signal(SIGVTALRM, signal_handeler) == SIG_ERR) {
        perror("signal");
        return 1;
    }

    printf("Throwing SIGVTALRM in 1 second of CPU time....\n");
    
    struct itimerval timer;
    timer.it_value.tv_sec = 1;       
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    if(setitimer(ITIMER_VIRTUAL,&timer,NULL)== -1){
        perror("setitimer");
        return 1;
    }

    for(;;){
    }
    return 0;
}
/*
Output:

$ ./a.out 
Throwing SIGVTALRM in 1 second of CPU time....
SIGVTALRM caught!

*/