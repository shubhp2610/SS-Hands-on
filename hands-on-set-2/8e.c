/*
============================================================================
Name : 8e.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : 8. Write a separate program using signal system call to catch the following signals.
                 e. SIGALRM (use setitimer system call)
Date: 15th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

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
    
    struct itimerval timer;
    timer.it_value.tv_sec = 2;       
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    if(setitimer(ITIMER_REAL,&timer,NULL)== -1){
        perror("setitimer");
        return 1;
    }

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