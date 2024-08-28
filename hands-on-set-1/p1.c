/*
Name: Shubh Sanjaykumar Patel
Roll No.: MT2024148
Problem No.: 1
Problem statement: Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
*/
//using system call
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(){
    char *source = "file";
    char *destSym = "fileSym";
    char *myFifo = "myFifo";
    int symlnk = symlink(source,destSym);
    if(symlnk==-1){
        perror("symlink error");
        return 1;
    }
    printf("Symbolic link created successfully!\n");
    char *destHard = "fileHard";
    int hardlnk = link(source,destHard);
    if(symlnk==-1){
        perror("link error");
        return 1;
    }
    printf("Hard link created successfully!\n");
    int fifo = mkfifo(myFifo, 0644);
    if(fifo==-1){
        perror("fifo error");
        return 1;
    }
    printf("FIFO created successfully!\n");

    return 0;
}

/*
OUTPUT:
$ ls -il
3539310 -rw-rw-r-- 2 ubuntu ubuntu     0 Aug 28 19:32  file
3539310 -rw-rw-r-- 2 ubuntu ubuntu     0 Aug 28 19:32  fileHard
3543024 lrwxrwxrwx 1 ubuntu ubuntu     4 Aug 28 19:34  fileSym -> file
3543025 prw-r--r-- 1 ubuntu ubuntu     0 Aug 28 19:34  myFifo

The inode value for hard link stays same.
*/