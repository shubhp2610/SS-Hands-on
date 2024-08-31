
# ============================================================================
# Name : 1.sh
# Author : Shubh Sanjaykumar Patel (MT2024148)
# Description : Create the following types of a files using (i) shell command (ii) system call
#                 a. soft link (symlink system call)
#                 b. hard link (link system call)
#                 c. FIFO (mkfifo Library Function or mknod system call)
# Date: 28th Aug, 2024.
# ============================================================================

touch file
# a. soft link
ln -s file fileSym
echo "Soft link created \"fileSym\""
# b. hard link
ln file fileHard
echo "Hard link created \"fileHard\""
# c. FIFO
mkfifo myFifo
echo "FIFO ceated \"myFifo\""

# Output:
# $ sh p1.sh
# Soft link created "fileSym"
# Hard link created "fileHard"
# FIFO ceated "myFifo"
# $ ls -l
# -rw-rw-r-- 2 ubuntu ubuntu    0 Aug 28 12:47  file
# -rw-rw-r-- 2 ubuntu ubuntu    0 Aug 28 12:47  fileHard
# lrwxrwxrwx 1 ubuntu ubuntu    4 Aug 28 12:47  fileSym -> file
# prw-rw-r-- 1 ubuntu ubuntu    0 Aug 28 12:47  myFifo
