/*
============================================================================
Name : p29.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,SCHED_RR).
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
void print_scheduler(pid_t pid){
    int policy = sched_getscheduler(pid);
    if (policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }
    printf("Current scheduling policy ");
    if (policy == SCHED_OTHER) {
        printf("SCHED_OTHER (standard round-robin)\n");
    } else if (policy == SCHED_FIFO) {
        printf("SCHED_FIFO\n");
    } else if (policy == SCHED_RR) {
        printf("SCHED_RR\n");
    }
}
int main() {
    struct sched_param param;
    pid_t pid = getpid();
    
    print_scheduler(pid);

    param.sched_priority = 1;  
    int new_policy = SCHED_FIFO; 
    if (sched_setscheduler(pid, new_policy, &param) == -1) {
        perror("sched_setscheduler");
        return 1;
    } else {
        printf("Scheduling policy changed successfully to FIFO.\n");
    }
    
    print_scheduler(pid);
    return 0;
}

