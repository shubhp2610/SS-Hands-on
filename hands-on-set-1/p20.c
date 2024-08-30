/*
============================================================================
Name : p20.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 29th Aug, 2024.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/resource.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
    pid_t pid = getpid();
    int curr_priority = getpriority(PRIO_PROCESS, pid);
    if (curr_priority == -1 && errno != 0) {
        perror("getpriority");
        exit(EXIT_FAILURE);
    }
    printf("Priority of the current process: %d.\n",curr_priority);

    int nice_status = nice(-20);
    if (nice_status == -1 && errno != 0) {
        perror("nice");
        return 1;
    }
    printf("Updated priority of the current process: %d.\n",nice_status);
    return 0;
}
       