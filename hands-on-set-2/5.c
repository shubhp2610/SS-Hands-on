/*
============================================================================
Name : 5.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to print the system limitation of
                a. maximum length of the arguments to the exec family of functions.
                b. maximum number of simultaneous process per user id.
                c. number of clock ticks (jiffy) per second.
                d. maximum number of open files
                e. size of a page
                f. total number of pages in the physical memory
                g. number of currently available pages in the physical memory.
Date: 20th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/resource.h>
#include <limits.h>

int main() {
    long arg_max = sysconf(_SC_ARG_MAX);
    printf("maximum length of arguments to exec family: %ld bytes\n", arg_max);

    struct rlimit rlim;
    if (getrlimit(RLIMIT_NPROC, &rlim) == 0) {
        printf("maximum number of simultaneous processes: %ld\n", rlim.rlim_max);
    } else {
        perror("getrlimit");
    }

    long ticks_per_sec = sysconf(_SC_CLK_TCK);
    printf("number of clock ticks (jiffy) per second: %ld\n", ticks_per_sec);

    if (getrlimit(RLIMIT_NOFILE, &rlim) == 0) {
        printf("maximum number of open files: %ld\n", rlim.rlim_max);
    } else {
        perror("getrlimit");
    }

    long page_size = sysconf(_SC_PAGESIZE);
    printf("size of a page: %ld bytes\n", page_size);

    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        long total_pages = info.totalram / page_size;
        printf("total number of pages in physical memory: %ld\n", total_pages);
        long free_pages = info.freeram / page_size;
        printf("number of currently available pages in physical memory: %ld\n", free_pages);
    } else {
        perror("sysinfo");
    }

    return 0;
}
/* Output

$ gcc 5.c && ./a.out 
maximum length of arguments to exec family: 2097152 bytes
maximum number of simultaneous processes: 59394
number of clock ticks (jiffy) per second: 100
maximum number of open files: 1048576
size of a page: 4096 bytes
total number of pages in physical memory: 3820011
number of currently available pages in physical memory: 2230906
*/