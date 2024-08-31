/*
============================================================================
Name : 19.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
unsigned long long int rdtsc(){
    unsigned long long int dst;
    //(Read Time-Stamp Counter) instruction, this reads CPU's time-stamp counter
    __asm__ __volatile__ ("rdtsc":"=A" (dst));
    return dst;
}
int main(){
    unsigned long long int start, end;
    start = rdtsc();
    for(int i=0;i<50000;i++){
        pid_t getpid(void);
    }
    end = rdtsc();
    unsigned long long int out = (end-start)/(2*1e3); // divided by cpu feq * (10^3)
    printf("time taken %lld micro seconds\n",out);
    return 0;
}

/*
Output:
$ ./a.out
time taken 178 micro seconds
*/
