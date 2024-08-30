/*
============================================================================
Name : p15.c
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
