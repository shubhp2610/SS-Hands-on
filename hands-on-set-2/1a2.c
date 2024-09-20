/*
============================================================================
Name : 1a2.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a separate program (for each time domain) to set a interval timer in 10 micro second
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
unsigned long long int start,end;
unsigned long long int rdtsc(){
    unsigned long long int dst;
    __asm__ __volatile__ ("rdtsc":"=A" (dst));
    return dst;
}
void alarm_handeler(int sig) {
    printf("SIGALRM timer expired!\n");
    end = rdtsc();
    printf("time taken %lld micro seconds\n",(end-start)/(2000));    
    exit(0);
}
int main() {
    struct itimerval timer;
    signal(SIGALRM, alarm_handeler);
    
    timer.it_value.tv_sec = 0;       
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("setitimer");
        return 1;
    }

    printf("ITIMER_REAL timer set for 10 us.\n");
    start = rdtsc();
    for(;;){
    }
    return 0;
}


/*
Output:
$ gcc 1a2.c && ./a.out 
SIGALRM timer expired!
time taken 328196 micro seconds

*/
