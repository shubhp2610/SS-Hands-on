/*
============================================================================
Name : 17_createDB.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to simulate online ticket reservation. Implement write lock
              Write a program to open a file, store a ticket number and exit. Write a separate program, to
              open the file, implement write lock, read the ticket number, increment the number and print
              the new ticket number then close the file.
Date: 21th Aug, 2024.
============================================================================
*/
// creating db wth provided ticket number
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    
    struct {
    int ticket_number;
    } db;
    
    db.ticket_number = 0;
    int fd = open("db", O_CREAT|O_RDWR, 0644);
    if(fd==-1){
		perror("Error opening file.");
		return 1;
	}
    write(fd, &db, sizeof(db));
    close(fd);
    printf("Done creating database file.\n");
    return 0;
}
/*
Output:
$ ./a.out 
Done creating database file.
*/