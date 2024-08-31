/*
============================================================================
Name : 13.c
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
    fd_set rfds;       // structure to specify multiple file descriptors
    struct timeval tv; // structure to set maximum waiting time
    
    FD_ZERO(&rfds);    // clear rfds
    FD_SET(0, &rfds);  // add STDIN to rfds
    
    tv.tv_sec = 10;    // Set timeout
    tv.tv_usec = 0;    
    
    // args(max fd +1, readability, writing, exceptional, timeout)
    int select_output = select(1, &rfds, NULL, NULL, &tv);

    if (select_output == -1) {
        perror("select error");
    } else if (select_output) {  // retval > 0
        printf("Data is available now. select_output = %d\n",select_output);
    } else {   // retval == 0
        printf("No data within ten seconds.\n");
    }
    return;
}

/*
Output:
---------- No input given -----------
$ ./p13
No data within five seconds.

---------- With input given -----------
$ ./p13
Hello world
Data is available now. select_output = 1
$ Hello world
*/
