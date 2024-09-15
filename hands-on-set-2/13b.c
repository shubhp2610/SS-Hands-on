/*
============================================================================
Name : 13b.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 12th Sept, 2024.
============================================================================
*/
//killing the process
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char **argv) {
    printf("Sending SIGSTOP to process id:%d\n",atoi(argv[1]));
    if(kill(atoi(argv[1]),SIGSTOP)==-1){
        perror("kill");
        return 1;
    }
    printf("SIGSTOP sent.\n");
    return 0;
}

/*
Output:
$ ./a.out 26232
Sending SIGSTOP to process id:26232
SIGSTOP sent.
*/
