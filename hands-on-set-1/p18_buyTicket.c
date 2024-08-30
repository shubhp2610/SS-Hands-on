/*
============================================================================
Name : p18_buyTicket.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to perform Record locking.
                    a. Implement write lock
                    b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 21th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    struct {
    int train_number;
    int ticket_sold;
    } db;

    int fd = open("db", O_RDWR);
    if(fd==-1){
		perror("Error opening file.");
		return 1;
	}
    int train_no;
    while(1){
        printf("\n----------------------------------\n");
        printf("Select train: 1, 2, 3, 4, 5 or enter 0 to exit.\n");
        scanf("%d", &train_no);
        if(train_no==0){
            printf("Thank you!\n");
            break;
        }
        struct flock lock;
        lock.l_type = F_WRLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = (train_no - 1) * sizeof(db); //train 1 is at index 0
        lock.l_len = sizeof(db);
        lock.l_pid = getpid(); 
        //acquiring write lock
        printf("Acquiring write lock to prevent double booking.\n");
        fcntl(fd, F_SETLKW, &lock);
        printf("Write lock acquired. Booking ticket....\n");
        // reading present booking number
        lseek(fd, (train_no - 1) * sizeof(db), SEEK_SET);
        read(fd, &db, sizeof(db));
        db.ticket_sold++;
        //updating booking number
        lseek(fd, -1 * sizeof(db), SEEK_CUR);
        write(fd, &db, sizeof(db));
        printf("Ticket booked! Booking number : %d\n", db.ticket_sold);
        getchar();
        //releasing lock
        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
    }

    return 0;
}