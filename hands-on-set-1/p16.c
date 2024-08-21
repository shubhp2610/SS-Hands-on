/*
Name: Shubh Sanjaykumar Patel
Roll No.: MT2024148
Problem No.: 16
Problem statement: Write a program to perform mandatory locking.
                    a. Implement write lock
                    b. Implement read lock
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
int main() {
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    int fd = open("test_file", O_RDWR | O_CREAT, 0644);
    if(fd==-1){
		perror("Error opening file.");
		return;
	}
    
    //WRITE LOCK
    printf("Acquiring write lock.\n");
    fcntl(fd, F_SETLKW, &lock);
    printf("Inside the critical section! Press enter to unlock.....");
    getchar();
    printf("File unlocked!\n");
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    sleep(5); //during this time other process can acquire read/write lock.

    //READ LOCK
    printf("Acquiring read lock\n");
    lock.l_type = F_RDLCK;
    fcntl(fd, F_SETLKW, &lock);
    printf("Inside the critical section! Press enter to unlock.....");
    getchar();
    printf("File unlocked!\n");
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    return 0;
}