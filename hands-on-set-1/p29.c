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
        exit(EXIT_FAILURE);
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
void set_scheduler(pid_t pid, int new_policy){
    struct sched_param param;
    param.sched_priority = 50;
    if (sched_setscheduler(pid, new_policy, &param) == -1) {
        perror("sched_setscheduler");
        exit(EXIT_FAILURE);
    } else {
        printf("Scheduling policy changed successfully!\n");
    }
}
int main() {
    
    pid_t pid = getpid();
    printf("pid = %d\n",pid);
    print_scheduler(pid);
    sleep(10);
    // setting FIFO scheduler
    int new_policy = SCHED_FIFO; 
    set_scheduler(pid,new_policy);
    print_scheduler(pid);
    sleep(10);
    // setting RR scheduler
    new_policy = SCHED_RR; 
    set_scheduler(pid,new_policy);
    print_scheduler(pid);
    sleep(10);
    return 0;
}

