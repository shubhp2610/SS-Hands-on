/*
============================================================================
Name : p13.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 20th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

void main(void) {
    int retval;
    fd_set rfds;       // structure to specify multiple file descriptors
    struct timeval tv; // structure to set maximum waiting time
    
    FD_ZERO(&rfds);    // clear rfds
    FD_SET(0, &rfds);  // add STDIN to rfds
    
    tv.tv_sec = 10;    // Set timeout
    tv.tv_usec = 0;    
    
    // args(max fd +1, readability, writing, exceptional, timeout)
    retval = select(1, &rfds, NULL, NULL, &tv);

    if (retval == -1) {
        perror("select error");
    } else if (retval) {  // retval > 0
        printf("Data is available now. retval = %d\n",retval);
    } else {   // retval == 0
        printf("No data within five seconds.\n");
    }
    return;
}
