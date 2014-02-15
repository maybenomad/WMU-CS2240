#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "shell.h"

void shell() 
{
	while (1)
	{
		// Retrieve PID of the parent process. 
		pid_t shell_pid = getpid();

		// Print shell prompt. 
		printf("{%i}$ ", shell_pid);

		// Retrieve input from stdin.
		char* input = NULL;
		size_t input_size = 0;
		getline(&input, &input_size, stdin);

		// Create a child process to handle user input. 
		pid_t pid = fork();

		// Parent process.  
		if (pid != 0) 
		{
			wait(NULL);
		} 
		else // Child process
		{
			// Handle user input here!

			// Keep this here or else we'll have a fork bomb!
			exit(0);
		}

		// Free memory allocated by getline(). 
		free(input);
	}
}
