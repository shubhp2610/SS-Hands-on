/*
============================================================================
Name : 27e.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to execute ls -Rl by the following system calls.
              e. execvp
Date: 30th Aug, 2024.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
int main(){
    char *arg[] = {"-R", "-l", NULL};
    if(execvp("/bin/ls", arg)==-1){
        perror("execvp error");
        return 1;
    } 
    return 0;
}

/*
Ouput:
$ ./a.out 
.:
total 196
-rw-rw-r-- 1 ubuntu ubuntu  1522 Aug 30 13:35  10.c
-rw-rw-r-- 1 ubuntu ubuntu  1971 Aug 30 13:36  11.c
-rw-rw-r-- 1 ubuntu ubuntu  1292 Aug 30 13:37  12.c

*/