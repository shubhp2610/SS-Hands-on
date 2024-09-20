/*
============================================================================
Name : 2.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <limits.h>

void print_resource_limit(int resource) {
    struct rlimit rlim;
    if (getrlimit(resource, &rlim) == -1) {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }
    printf("Soft limit: %ld\n", rlim.rlim_cur);
    printf("Hard limit: %ld\n", rlim.rlim_max);
}

int main() {
    printf("Processes limits:\n");
    print_resource_limit(RLIMIT_NPROC);
    printf("Open files limits:\n");
    print_resource_limit(RLIMIT_NOFILE);
    return 0;
}

/*
Output
$ gcc 2.c && ./a.out 
Processes limits:
Soft limit: 59394
Hard limit: 59394
Open files limits:
Soft limit: 1024
Hard limit: 1048576

*/