# A4: Parallel Sort

In this assignment you will be subjected to a 100% completely realistic scenario. Somebody borked our database and now the records are all chopped up and out of order. So now it's YOUR job to clean up this mess and write a program to sort these back into a single file. Oh, and we only have a few nanoseconds to do it, so you'd better do it with pthreads!

# The Assignment

## Input Data
As input, you will receive an arbitrary number of ASCII text files with arbitrary file names. These files will all be located in a directory specified on the command line. You are given a set of sample data with which to test your program.

Your program should obtain a list of the files in a given directory and then use that to go about its business. 

Each data file will have a number of records that look like the following: 

    <username>,<password><blood type>,<domain name>,<database index>

You may read these in with any file manipulation function that you see fit (`fgets()` works quite nicely). You should split these on commas and use `atoi()` on the database index before sticking them into a struct. 

The end result will be an array of these structs to be sorted. 

## Parallelism
Each file should be handled in parallel. This means that you will list the supplied directory and then spin up a separate thread for each file contained therein. 

All file manipulation functions and sorting will take place in the thread allotted for that file. 

## Sorting 
You can write your own sort if you'd like, but since that's not relevant to the assignment, you can go ahead and use the `qsort()` function in the standard library. You will be sorting by the last field in each record, the `database id`. The result should be in ascending order. 

Note that this function takes a function pointer as an argument. This is a pointer to another function in memory which is used to compare elements in the array. You will learn more about how this works in class. 

## Makefile
Your makefile should produce an executable which takes one argument (a directory path) and performs a sort on the files located in that directory. Make sure that you are processing this argument in a fashion that finds the directory relative to the current working directory. (e.g., if you execute `./coolsort "./nested/directory/structure"`, everything in the subdirectory "structure" should be sorted). 

## Output
The output should be a single ASCII file called `sorted.yay` containing all of the records from each individual data file in sorted order. 

## Other Things
I am not responsible for anything that you may find at any of the domain names in the test data. 

Good luck and have fun. 

