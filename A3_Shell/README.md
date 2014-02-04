# A3: Shell

## The Assignment
The goal of this assignment is to construct a rudimentary implementation of a shell. This will require knowledge of everything that we've learned so far (string manipulation, memory model) as well as a solid understanding of a powerful Unix primitive: the process. 

At its core, the shell is simply an overglorified infinite loop. On each iteration, it prints a prompt, reads a command (from stdin) and then carries out various actions based on the command received. 

### Prompt
The prompt has been provided for you. You are allowed to change it, so long as the beginning of the prompt consists of the shell's PID surrounded by stache tags. 

### Input 
User input has also been taken care of for you. This is done using the `getline()` function. `getline()` is very powerful in that it is capable of reading in a buffer of arbitrary size and will allocate space accordingly. You have to make sure to free this space, however!

After input has been received, it must be tokenized on spaces so that you may effectively deal with the command. 

### Commands
There are two types of commands: builtins and non. Builtin commands are handled directly by the shell executable itself. Non-builtin commands must be handled by external executables. 

## The Specs
**Builtins:** You should implement `echo`, `cd` and `exit` as builtins. 

**Non-builtins:** Your shell should be able to execute any external executable via the `execve()` command. 

**Piping:** You should be able to handle an arbitrary amount of pipes. 

**Redirection:** You should be able to handle the two basic types of redirection: `>` should redirect a process' stdout to a file, `<` should redirect a file to a process' stdin. 

**(Bonus) Globbing:** Your shell should be able to handle basic globbing with the * operator. This is optional, but it would be really cool! 

### Due: February 18th, 2014

## The Grade
Your assignment will be compiled and run through an automated test suite. For this reason, it is IMPERATIVE that you stick to the guidelines and naming conventions. If you do not, your code will not interact properly with the tests and you will be injustly rewarded with a bad grade.