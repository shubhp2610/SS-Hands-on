/*
Name: Shubh Sanjaykumar Patel
Roll No.: MT2024148
Problem No.: 9
Problem statement: Write a program to print the following information about a given file. a. inode b. number of hard links c. uid
d. gid e. size f. block size g. number of blocks h. time of last access i. time of last modification
j. time of last change
*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <time.h>

void main(int argc, char * argv[]) {
  struct stat sb;
  // checking for correct input
  if(argc<2){
    printf("Error: please specify a file name!\n");
    printf("Usage: ./p9 <filename>\n");
    return;
  }
  if (lstat(argv[1], & sb) == -1) {
    perror("lstat error");
    return;
  }
  printf("I-node number:             %ju\n", (uintmax_t) sb.st_ino);
  printf("Hard link count:           %ju\n", (uintmax_t) sb.st_nlink);
  printf("UID:                       %ju\n", (uintmax_t) sb.st_uid);  
  printf("GID:                       %ju\n", (uintmax_t) sb.st_gid);
  printf("File size:                 %jd bytes\n", (intmax_t) sb.st_size);
  printf("I/O block size:            %jd bytes\n", (intmax_t) sb.st_blksize);
  printf("Blocks allocated:          %jd\n", (intmax_t) sb.st_blocks);
  printf("Time of last access:       %s", ctime( & sb.st_atime));
  printf("Time of last modification: %s", ctime( & sb.st_mtime));
  printf("Time of Last change:       %s", ctime( & sb.st_ctime));
  return;
}