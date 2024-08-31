/*
============================================================================
Name : 16a.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to perform mandatory locking.
                    a. Implement write lock
                    b. Implement read lock
Date: 21th Aug, 2024.
============================================================================
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

    int fd = open("test_file", O_WRONLY | O_CREAT, 0644);
    if(fd==-1){
		perror("Error opening file.");
		return 1;
	}
    
    printf("Acquiring write lock.\n");
    fcntl(fd, F_SETLKW, &lock);
    printf("Inside the critical section! Press enter to unlock.....");
    getchar();
    printf("File unlocked!\n");
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    return 0;
}

/*
Output:

$ ./p16a
Acquiring write lock.
Inside the critical section! Press enter to unlock.....
File unlocked!
*/