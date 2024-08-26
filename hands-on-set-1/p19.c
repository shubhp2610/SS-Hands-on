/*
Name: Shubh Sanjaykumar Patel
Roll No.: MT2024148
Problem No.: 19
Problem statement: Write a program to find out time taken to execute getpid system call. Use time stamp counter.
*/
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(){
    struct timeval start, stop;
    double secs = 0;

    gettimeofday(&start, NULL);
    
    pid_t getpid(void);
    
    gettimeofday(&stop, NULL);
    secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    printf("time taken %f seconds\n",secs);
    return 0;
}
