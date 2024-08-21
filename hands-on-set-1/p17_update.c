/*
Name: Shubh Sanjaykumar Patel
Roll No.: MT2024148
Problem No.: 17
Problem statement: Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
*/
// Reading and incrementing the ticket number.
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

    struct {
    int ticket_number;
    } db;

    int fd = open("db", O_RDWR);
    printf("Acquiring write lock.\n");
    fcntl(fd, F_SETLKW, &lock);
    printf("Lock acquired!\n");
    read(fd, &db, sizeof(db));
    if(fd==-1){
		perror("Error opening file.");
		return 1;
	}
    printf("Ticket number read from database : %d\n", db.ticket_number);
    db.ticket_number++;
    lseek(fd,0,SEEK_SET); //resetting cursor to start
    write(fd, &db, sizeof(db));
    close(fd);
    printf("Done writing new ticket number : %d\n",db.ticket_number);
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("File unlocked!\n");
    return 0;
}