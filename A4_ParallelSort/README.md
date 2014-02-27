# A4: Parallel Sort

In this assignment you will be sorting multiple text files in parallel using POSIX threads (or pthreads, for short). 

# The Assignment

## Input Data
As input, you will receive an arbitrary number of ASCII text files with arbitrary file names. These files will all be located in a directory specified on the command line. You are given a set of sample data with which to test your program.

Your program should obtain a list of the files in a given directory and then use that to go about its business. 

Each data file will have a number of records that look like the following: 

    <string>,<integer>

You may read these in with any file manipulation function that you see fit (`fgets()` works quite nicely). You should split each record on the comma, use `atoi()` to obtain an integer from the second value, and then stick these into a struct. 

The end result will be an array of structs to be sorted. 

## Parallelism
Each file should be handled in parallel. This means that you will list the supplied directory and then spin up a separate thread for each file contained therein. 

All file manipulation functions and sorting will take place in the thread allotted for that file. 

## Sorting 
You can write your own sort if you'd like, but since that's not relevant to the assignment, you can go ahead and use the `qsort()` function in the standard library. 

Note that this function takes a function pointer as an argument. This is a pointer to another function in memory which is used to compare elements in the array. You will learn more about how this works in class. 

# Makefile
Your makefile should produce an executable which takes one argument (a directory path) and performs a sort on the files located in that directory. Make sure that you are processing this argument in a fashion that finds the directory relative to the current working directory. (e.g., if you execute `./coolsort "./nested/directory/structure"`, everything in the subdirectory "structure" should be sorted). 



