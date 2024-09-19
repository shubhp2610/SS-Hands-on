/*
============================================================================
Name : 19.c
Author : Shubh Sanjaykumar Patel (MT2024148)
Description : 19. Create a FIFO file by
                a. mknod command
                b. mkfifo command
                c. use strace command to find out, which command (mknod or mkfifo) is better.
Date: 19th Sept, 2024.
============================================================================

a. $ mknod fifo1 p

b. $ mkfifo fifo2

c. On my system the mkfifo does not show fdmod in strace. 
   But comparing the time mknod is faster than mkfifo.

ubuntu@ubuntu:~/Desktop/SS-Hands-on/hands-on-set-2$ strace -c mknod fifo1 p
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
 31.43    0.000280          15        18           mmap
 12.46    0.000111          22         5           mprotect
 11.45    0.000102         102         1           mknodat
  6.85    0.000061          10         6           openat
  6.73    0.000060          12         5           read
  6.62    0.000059           7         8           close
  5.05    0.000045          45         1           munmap
  4.26    0.000038          19         2         2 statfs
  4.15    0.000037           6         6           newfstatat
  2.47    0.000022           7         3           brk
  1.91    0.000017           8         2         2 access
  1.23    0.000011          11         1           set_tid_address
  1.23    0.000011          11         1           getrandom
  1.12    0.000010          10         1           prlimit64
  1.01    0.000009           4         2         1 arch_prctl
  1.01    0.000009           9         1           set_robust_list
  1.01    0.000009           9         1           rseq
  0.00    0.000000           0         2           pread64
  0.00    0.000000           0         1           execve
------ ----------- ----------- --------- --------- ----------------
100.00    0.000891          13        67         5 total
ubuntu@ubuntu:~/Desktop/SS-Hands-on/hands-on-set-2$ strace -c mkfifo fifo2
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
 29.85    0.000283          15        18           mmap
 11.18    0.000106         106         1           mknodat
 10.86    0.000103          20         5           mprotect
  9.49    0.000090          18         5           read
  7.59    0.000072           9         8           close
  7.38    0.000070          11         6           openat
  4.75    0.000045          45         1           munmap
  4.22    0.000040           6         6           newfstatat
  4.11    0.000039          19         2         2 statfs
  2.64    0.000025          12         2         2 access
  2.11    0.000020           6         3           brk
  1.05    0.000010          10         1           prlimit64
  1.05    0.000010          10         1           getrandom
  0.95    0.000009           4         2         1 arch_prctl
  0.95    0.000009           9         1           set_robust_list
  0.95    0.000009           9         1           rseq
  0.84    0.000008           8         1           set_tid_address
  0.00    0.000000           0         2           pread64
  0.00    0.000000           0         1           execve
------ ----------- ----------- --------- --------- ----------------
100.00    0.000948          14        67         5 total
*/

