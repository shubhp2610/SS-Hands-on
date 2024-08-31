/*
============================================================================
Name : 14.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : Write a program to find the type of a file.
                    a. Input should be taken from command line.
                    b. program should be able to identify any type of a file.
Date: 21th Aug, 2024.
============================================================================
*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <time.h>

void main(int argc, char *argv[]) {
  struct stat sb;
  // checking for correct input
  if(argc<2){
    printf("Error: please specify a file name!\n");
    printf("Usage: %s <filename>\n",argv[0]);
    return;
  }
  if (lstat(argv[1], & sb) == -1) {
    perror("lstat error");
    return;
  }
  printf("%s is ",argv[1]);
  // matching sb.st_mode with predefined file types
  switch (sb.st_mode & S_IFMT) {
    case S_IFBLK:
      printf("a block device.\n");
      break;
    case S_IFCHR:
      printf("a character device.\n");
      break;
    case S_IFDIR:
      printf("a directory.\n");
      break;
    case S_IFIFO:
      printf("a FIFO/pipe.\n");
      break;
    case S_IFLNK:
      printf("a symlink.\n");
      break;
    case S_IFREG:
      printf("an regular file.\n");
      break;
    case S_IFSOCK:
      printf("a socket.\n");
      break;
    default:
      printf("a unknown file.\n");
      break;
  }
  return;
}

/*
output:
$ mkdir test
$ mkfifo testFifo

$ ./p14 13.c
13.c is an regular file.
$ ./p14 test
test is a directory.
$ ./p14 testFifo
testFifo is a FIFO/pipe.

*/