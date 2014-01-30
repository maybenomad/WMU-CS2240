# A2: BYOB (Bring Your Own Bytes)

## The Assignment
For most programmers, memory allocation is seen as some sort of black magic. In Java, the JVM takes care of allocation automatically and has a complex garbage collector to handle deallocation. Scripting languages such as Python and Ruby also have complex object management systems. Even in C, it is easy to simply call `malloc` and `free` without giving too much thought to what happens behind the scenes. 

In this assignment, you'll be tasked with implementing your own memory management scheme, namely re-building the Unix system calls `malloc`, `calloc`, `realloc`, and `free`. It should go without saying that you must accomplish this without actually using any of the original libc calls. 

What you *will* be able to use, however, is a system call named `sbrk()`. This system call takes a `size_t size`, pushing the heap break down the heap by that many bytes. It then returns a pointer to the break's old position, effectively giving you a pointer to a new chunk of allocated space `size` bytes long. (For help visualizing this, search for more information on the layout of the heap).

Your library will be responsible for utilizing `sbrk()` as well as performing book-keeping with regards to what memory has been allocated by the user and what memory is free. 

## The Files
Not much explanation here. A basic header and implementation file are provided. Fill them in. 

## The Protos 

Logically, this assignment should be divided into two parts. The initial goal is just to construct working implementations of the aforementioned functions. Make them as naive as possible, just make them work. 

After this, you will need to incorporate a more complex data structure of your choosing to do the bookkeeping required of a proper memory management library. Your options on this front will be discussed in more detail in class. 

The following prototypes are ripped directly from the manpages (and prepended with nu_, of course). I shouldn't have to explain them here - from an outside perspective, they should behave exactly as their libc counterparts do. Use `man` if you are looking for more details. 

```c
void* nu_malloc(size_t size);
```

```c 
void* nu_calloc(size_t count, size_t size);
```

```c
void* nu_realloc(void* ptr, size_t size);
```

```c
void nu_free(void* ptr);
```

### Due: February 4th, 2014

## The Grade
Your assignment will be compiled and run through an automated test suite. For this reason, it is IMPERATIVE that you stick to the guidelines and naming conventions. If you do not, your code will not interact properly with the tests and you will be injustly rewarded with a bad grade.

In this assignment specifically, your program will be [ptraced](http://linux.die.net/man/2/ptrace) in order to ensure that proper memory allocation and deallocation techniques were performed. This automated grader is smart. ;)
