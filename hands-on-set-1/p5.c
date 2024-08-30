/*
============================================================================
Name : p5.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 20th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include <fcntl.h>
void main(void){
	//opening 3 which exists in pwd as read only.
	int fd1,fd2,fd3;
	char *f1 = "p2.c";
    char *f2 = "p3.c";
    char *f3 = "p4.c";
	fd1=open(f1, O_RDONLY);
    fd2=open(f2, O_RDONLY);
	fd3=open(f3, O_RDONLY);
	if(fd1==-1 || fd2==-1 || fd3==-1){
	printf("Error opening files !");
	return;
	}
	for(;;);
}
/*contents of fd folder
lrwx------ 1 ubuntu ubuntu 64 Aug 20 16:02 0 -> /dev/pts/2
lrwx------ 1 ubuntu ubuntu 64 Aug 20 16:02 1 -> /dev/pts/2
lrwx------ 1 ubuntu ubuntu 64 Aug 20 16:02 2 -> /dev/pts/2
lr-x------ 1 ubuntu ubuntu 64 Aug 20 16:02 3 -> /home/ubuntu/Desktop/hand/p2.c
lr-x------ 1 ubuntu ubuntu 64 Aug 20 16:02 4 -> /home/ubuntu/Desktop/hand/p3.c
lr-x------ 1 ubuntu ubuntu 64 Aug 20 16:02 5 -> /home/ubuntu/Desktop/hand/p4.c
*/