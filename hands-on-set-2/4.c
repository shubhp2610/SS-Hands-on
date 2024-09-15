/*
============================================================================
Name : 4.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 12th Sept, 2024.
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
    for(int i=0;i<100;i++){
        pid_t getppid(void);
    }
    end = rdtsc();
    unsigned long long int out = (end-start)/(2); // divided by cpu feq
    printf("time taken %lld nano seconds\n",out);
    return 0;
}

/*
Output:
$ ./a.out
time taken 430 nano seconds
*/
