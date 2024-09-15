/*
============================================================================
Name : 13a.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 12th Sept, 2024.
============================================================================
*/
//handeling SIGSTOP
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigstop_handeler(int sig){
    printf("SIGSTOP PREVENTED!\n");
}

int main() {

    signal(SIGSTOP, sigstop_handeler); 
    printf("Process ID: %d",getpid());
    printf("\nBypassing SIGSTOP for next 30 seconds.\n");
    sleep(30);
    return 0;
}

/*
Output:
$ ./a.out 
Process ID: 26232
Bypassing SIGINT for next 30 seconds.

[2]+  Stopped                 ./a.out

Clearly we cannot catch the SIGSTOP or ignore it.

*/