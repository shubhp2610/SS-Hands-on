/*
============================================================================
Name : 1c2.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a separate program (for each time domain) to set a interval timer in 10 micro second
                c. ITIMER_PROF
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
    printf("SIGPROF timer expired!\n");
    end = rdtsc();
    printf("time taken %lld micro seconds\n",(end-start)/(2000));    
    exit(0);
}
int main() {
    struct itimerval timer;
    signal(SIGPROF, alarm_handeler);
    
    timer.it_value.tv_sec = 0;       
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_PROF, &timer, NULL) == -1) {
        perror("setitimer");
        return 1;
    }

    printf("ITIMER_PROF timer set for 10 us.\n");
    start = rdtsc();
    for(;;){
    }
    return 0;
}


/*
Output:
$ gcc 1c2.c && ./a.out 
ITIMER_PROF timer set for 10 us.
SIGPROF timer expired!
time taken 5206 micro seconds

*/
