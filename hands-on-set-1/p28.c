/*
Name: Shubh Sanjaykumar Patel
Roll No.: MT2024148
Problem No.: 28
Problem statement: Write a program to get maximum and minimum real time priority.
*/
#include <stdio.h>
#include <sched.h>

int main() {
    int maxP, minP;

    maxP = sched_get_priority_max(SCHED_FIFO);
    if (maxP == -1) {
        perror("get_priority_max");
        return 1;
    }

    minP = sched_get_priority_min(SCHED_FIFO);
    if (minP == -1) {
        perror("get_priority_min");
        return 1;
    }

    printf("Realtime priorities for FIFO scheduling.\n");
    printf("Minimum priority: %d\n", minP);
    printf("Maximum priority: %d\n", maxP);

    return 0;
}
