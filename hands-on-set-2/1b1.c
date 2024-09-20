/*
============================================================================
Name : 1b1.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a separate program (for each time domain) to set a interval timer in 10sec
                b. ITIMER_VIRTUAL
Date: 20th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>
void alarm_handeler(int sig) {
    printf("SIGVTALRM timer expired!\n");
    printf("end epoch = %ld\n", time(NULL));
    exit(0);
}
int main() {
    struct itimerval timer;
    signal(SIGVTALRM, alarm_handeler);
    
    timer.it_value.tv_sec = 10;       
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("setitimer");
        return 1;
    }

    printf("ITIMER_VIRTUAL timer set for 10 seconds.\n");
    printf("start epoch = %ld\n", time(NULL));
    for(;;){
    }
    return 0;
}

/*
Output
$ gcc 1b1.c && ./a.out 
ITIMER_VIRTUAL timer set for 10 seconds.
start epoch = 1726762284
SIGVTALRM timer expired!
end epoch = 1726762294
*/