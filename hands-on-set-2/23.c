/*
============================================================================
Name : 23.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 18th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    long OPEN_MAX, PIPE_BUF;
    OPEN_MAX = sysconf(_SC_OPEN_MAX);
    PIPE_BUF = pathconf(".", _PC_PIPE_BUF);
    printf("Maximum number of files can be opened within a process : %ld\n",OPEN_MAX);
    printf("Size of a pipe (circular buffer) : %ld\n",PIPE_BUF);
    return 0;
}
/*
Output:
$ gcc 23.c && ./a.out 
Maximum number of files can be opened within a process : 1048576
Size of a pipe (circular buffer) : 4096
*/