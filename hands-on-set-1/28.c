/*
============================================================================
Name : 28.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to get maximum and minimum real time priority.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sched.h>
#include <errno.h>
int main() {
    int maxPF = sched_get_priority_max(SCHED_FIFO);
    int minPF = sched_get_priority_min(SCHED_FIFO);
    int maxPR = sched_get_priority_max(SCHED_RR);
    int minPR = sched_get_priority_min(SCHED_RR);
        
    if (maxPF == -1 || minPF == -1 || maxPR == -1 || minPR == -1) {
        perror("get_priority error");
        return 1;
    }

    printf("Realtime priorities for FIFO & RR scheduling.\n");
    printf("FIFO Minimum priority: %d\n", minPF);
    printf("FIFO Maximum priority: %d\n", maxPF);
    printf("RR Minimum priority: %d\n", minPR);
    printf("RR Maximum priority: %d\n", maxPR);
    return 0;
}

/*
Output:
$ ./a.out 
Realtime priorities for FIFO & RR scheduling.
FIFO Minimum priority: 1
FIFO Maximum priority: 99
RR Minimum priority: 1
RR Maximum priority: 99
*/