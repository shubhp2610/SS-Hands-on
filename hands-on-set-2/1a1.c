/*
============================================================================
Name : 1a1.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a separate program (for each time domain) to set a interval timer in 10sec
                a. ITIMER_REAL
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
    printf("SIGALRM timer expired!\n");
    printf("end epoch = %ld\n", time(NULL));
}

int main() {
    signal(SIGALRM, alarm_handeler);
    alarm(10);
    printf("SIGALRM timer set for 10 seconds.\n");
    printf("start epoch = %ld\n", time(NULL));
    pause();
    return 0;
}

/*
Output
$ gcc 1a1.c && ./a.out 
SIGALRM timer set for 10 seconds.
start epoch = 1726762413
SIGALRM timer expired!
end epoch = 1726762423
*/
