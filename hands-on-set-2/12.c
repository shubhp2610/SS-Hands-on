/*
============================================================================
Name : 12.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 12th Sept, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <signal.h>

void singla_handler(int sig) {
printf("PARENT: SIGINT interup interupt. Signla number: %d\n", sig);
exit(0);
}

int main(){
    int child = fork();
    if(!child){
        printf("CHILD : parent process id : %d\n",getppid());
        printf("CHILD: Sending SIGINT to parent in 2 second.\n");
        sleep(1);
        kill(getppid(),SIGINT);
        sleep(1);
        printf("CHILD : new parent process id : %d\n",getppid());
    }else{
        signal(SIGINT,singla_handler);
        printf("PARENT: sleeping for 5 seconds\n");
        sleep(5);
        printf("PARENT: execution completed without interupt.\n");
    }
    return 0;
}

/*
Output:
ubuntu@ubuntu:~/$ ./a.out 
PARENT: sleeping for 5 seconds
CHILD : parent process id : 32554
CHILD: Sending SIGINT to parent in 2 second.
PARENT: SIGINT interup interupt. Signla number: 2
ubuntu@ubuntu:~/$ CHILD : new parent process id : 2146
*/