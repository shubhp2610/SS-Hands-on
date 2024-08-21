/*
Name: Shubh Sanjaykumar Patel
Roll No.: MT2024148
Problem No.: 17
Problem statement: Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
*/
// creating db wth provided ticket number
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if(argc<2){
        printf("Error: please specify a ticket number!\n");
        printf("Usage: %s <ticket_number>\n",argv[0]);
        return 1;
    }
    
    struct {
    int ticket_number;
    } db;
    
    db.ticket_number = atoi(argv[1]);
    int fd = open("db", O_CREAT|O_RDWR, 0644);
    if(fd==-1){
		perror("Error opening file.");
		return;
	}
    write(fd, &db, sizeof(db));
    close(fd);
    printf("Done writing ticket number to file.\n");
    return 0;
}