#!/bin/bash
# ============================================================================
# Name : 7.sh
# Author : Shubh Sanjaykumar Patel (MT2024148)
# Description : Write a program to copy file1 into file2 ($cp file1 file2).
# Date: 20th Aug, 2024.
# ============================================================================

if [ "$#" -ne 2 ]; then
    echo "Error : two file name expected!"
    echo "Usage: $0 <source file> <destination file>"
    exit 1
fi
cp "$1" "$2"
if [ "$?" -eq 0 ]; then
    echo "File copied successfully."
else
    echo "Error occurred while copying the file."
    exit 1
fi

# Output:
# $ sh 7.sh 6.c code.c
# File copied successfully.

