# A2: BYOB (Bring Your Own Bytes)

## The Assignment
For most programmers, memory allocation is seen as some sort of black magic. In Java, the JVM takes care of allocation automatically and has a complex garbage collector to handle deallocation. Scripting languages such as Python and Ruby also have complex object management systems. Even in C, it is easy to simply call `malloc` and `free` without giving too much thought to what happens behind the scenes. 

In this assignment, you'll be tasked with implementing your own memory management scheme, namely re-building the Unix system calls `malloc`, `calloc`, `realloc`, and `free`. It should go without saying that you must accomplish this without actually using any of the original libc calls. 

What you *will* be able to use, however, is a system call named `sbrk()`. This system call takes a `size_t size`, pushing the heap break down the heap by that many bytes. It then returns a pointer to the break's old position, effectively giving you a pointer to a new chunk of allocated space `size` bytes long. (For help visualizing this, search for more information on the layout of the heap).

A malloc implementation could therefore be as simple as this:

```c
void* malloc(size_t size) {
  return sbrk(size);
}

void free(void* ptr) {
}
```

Unfortunately, this is a terrible implementation. If we simply move the heap break every time we need new space, we will eventually overrun the bounds of the heap and cause the program to crash. Due to this, a good memory management library must do some bookkeeping. 

The goal of said bookkeeping is to keep track of what memory on the heap has been allocated and what memory is free. When a user requests more memory, we must hand him/her a pointer to a sufficient amount of memory and then remember that this chunk of memory is in use. When the user requests that a chunk of memory be freed, we must be able to check that the pointer actually references a chunk of memory that we previously allocated and then mark that chunk as free (so it can be reused). 

The simplest way to do this involves building a linked-list-esque structure out of the heap. 

    -------------------------------
    |          METADATA           |--
    ------------------------------- |
    |                             | |
    |                             | |
    |         ALLOCATED           | |
    |           CHUNK             | |
    |                             | |
    ------------------------------- |
    |          METADATA           |<|
    ------------------------------- |
    |                             | |
    |                             | |
    |           FREE              | |
    |           CHUNK             | |
    |                             | |
    ------------------------------- |
    |          METADATA           |<|
    ------------------------------- 
    |                             | 
    |                             | 
    |         ALLOCATED           | 
    |           CHUNK             | 
    |                             | 
    ------------------------------- 
    
Each chunk of memory will be preceded by a struct containing metadata about that chunk. This metadata will form a linked list which spans from the beginning of the heap to the last chunk of memory that is available (with respect to the heap break). 

The struct will therefore look something like this: 

```c
typedef struct _heap_block heap_block;
struct _heap_block {
  int size;
  int free;
  heap_block* next;
};
```

In this scheme, `size` will contain the size (in bytes) of the block of memory, `free` will be either 0 or non-zero (0 meaning the memory is free, non-zero meaning it is allocated) and `next` will be a pointer to the next block of memory. By populating this struct with relevant data and placing an instance before each block of data, we will have solved the problem of indexing the heap and storing data about individual chunks in one fell swoop!

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

If you do anything clever in terms of bookkeeping, make sure to make note of it when you turn in your assignment! Extra points may be awarded for above-average implementations. 
