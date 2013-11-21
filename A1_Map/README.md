# A1: String Map

## The Assignment

A map or dictionary data structure is a key-value data store. Although the underlying implementation can vary drastically, a map's API generally looks very similar to an array, although with strings as indexes as opposed to decimal numbers. 

This assignment will have you producing your own implementation of a map. You will be using this data structure throughout the course on various assignments, so it's very important that you take your time and render a working project. 

## The Files

You are given three files - `map.h`, `map.c` and `test.c`.

`map.h` contains all of the required function prototypes as well as two skeleton structs. You may add members to these structs as you see fit, depending on how you choose to implement your map. The only requirement is that your top-level map type be called `map_t`. Here are the provided structs:

```c
typedef struct _map_entry {
      
} map_entry_t;

typedef struct _map {
  map_entry_t* entry;      
} map_t;
```

`map.c` contains empty function definitions for each of the functions required for the assignment. 

`test.c` contains unit tests built upon the provided API. You can run these whenever you'd like to test the functionality of your map. If your implementation works properly, all of the tests should pass. A fuller test suite will be run on the final assignment, so you should make sure to expand `test.c` if you think of any edge cases which are not being tested. 

## The Protos

```c
void map_init(map_t* self);
```
Initialize the dictionary structure. May be empty if no initialization logic is required. 

```c
int map_put(map_t* self, const char* key, const char* val);
```
Add an entry to the map with the provided key and value. Returns 0 on success.

```c
const char* map_get(map_t* self, const char* key);
```
Returns the value of the entry associated with the given key. If no value exists for the given key, returns `NULL`.

```c
int map_remove(map_t* self, const char* key);
```
Removes the entry associated with the given key. Returns 0 on success. 

```c
void map_destroy(map_t* self);
```
Cleans up the dictionary structure. May be entry if no cleanup is required. 


