/*
Name: Shubh Sanjaykumar Patel
Roll No.: MT2024148
Problem No.: 15
Problem statement: Write a program to display the environmental variable of the user (use environ).
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
