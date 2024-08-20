#!/bin/bash

#Name: Shubh Sanjaykumar Patel
#Roll No.: MT2024148
#Problem No.: 7
#Problem statement: Write a program to copy file1 into file2 ($cp file1 file2).

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
