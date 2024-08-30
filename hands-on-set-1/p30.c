/*
============================================================================
Name : p30.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 30th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h> 
#include<sys/types.h>
#include<sys/stat.h>

int main() {
    pid_t child = fork();
    if(!child) {
        //child process
        setsid(); //new session + deatch from the terminal
        while(1) {
            sleep(2);
            printf("PID: %d\n", getpid());
            printf("PPID: %d\n", getppid());
            printf("Daemon process is running...\n");
        }
    } else {
        //parent exit
        return 0;
    }
}

/*
OUTPUT:
$ ./p30
$ Daemon process is running...
PID: 22082
PPID: 2903 //systemd
*/