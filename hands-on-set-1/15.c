/*
============================================================================
Name : 15.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to display the environmental variable of the user (use environ).
Date: 21th Aug, 2024.
============================================================================
*/
#include <stdio.h>

extern char **environ;

int main(void){
	printf("===================== Environment Variables =====================\n");
	int i =0;
	while(environ[i]){
		printf("%s\n",environ[i]);
		i++;
	}
	printf("Total number of variables : %d\n",i);
	return 0;
}

/*
Output:
$ ./p15
===================== Environment Variables =====================
SHELL=/bin/bash
SESSION_MANAGER=local/ubuntu:@/tmp/.ICE-unix/2388,unix/ubuntu:/tmp/.ICE-unix/2388
QT_ACCESSIBILITY=1
NVM_RC_VERSION=
COLORTERM=truecolor
*/