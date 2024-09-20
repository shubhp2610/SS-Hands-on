/*
============================================================================
Name : 3.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
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

    printf("Open files limits:\n");
    print_resource_limit(RLIMIT_NOFILE);
    
    struct rlimit rlim;
    rlim.rlim_cur = 10;
    rlim.rlim_max = 100;
    if (setrlimit(RLIMIT_NOFILE, &rlim) == -1) {
        perror("setrlimit");
        return 1;
    }
    printf("\nOpen files limits updated!\n");
    
    printf("\nUpdated open files limits:\n");
    print_resource_limit(RLIMIT_NOFILE);
    
    return 0;
}

/*
Output
$ gcc 3.c && ./a.out 
Open files limits:
Soft limit: 1024
Hard limit: 1048576

Open files limits updated!

Updated open files limits:
Soft limit: 10
Hard limit: 100

*/