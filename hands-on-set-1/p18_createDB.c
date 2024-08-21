/*
Name: Shubh Sanjaykumar Patel
Roll No.: MT2024148
Problem No.: 18
Problem statement: Write a program to perform Record locking.
                    a. Implement write lock
                    b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
*/
//creating db file
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
    
    struct {
    int train_number;
    int ticket_sold;
    } db[5];

    for (int i=0; i<5; i++) {
        db[i].train_number = i+1;
        db[i].ticket_sold = 0;
    }
    // initializing db with 5 trains
    int fd = open("db", O_RDWR | O_CREAT, 0644);
    if(fd==-1){
		perror("Error opening file.");
		return 1;
	}

    write(fd, db, sizeof(db));
    return 0;
}