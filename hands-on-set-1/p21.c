/*
Name: Shubh Sanjaykumar Patel
Roll No.: MT2024148
Problem No.: 21
Problem statement: Write a program, call fork and print the parent and child process id.
*/
#include <stdio.h>
#include <unistd.h>
void main(){
    int child_id =  fork();
    if(child_id == 0){
        printf("\n--------- CHILD ---------\n");
        printf("child process id : %d\n",getpid());
        printf("parent process id : %d\n",getppid());
    }else{
        printf("\n--------- PARENT ---------\n");
        printf("child process id : %d\n",child_id);
        printf("parent process id : %d\n",getpid());
    }
}
       