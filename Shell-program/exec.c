#include <stdio.h>
#include <unistd.h>
#include "myheader.h"

/**
* main - execve example
*
* Return: Always 0.
*/
int main(void)
{
char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

printf("Before execve\n");
if (execve(argv[0], argv, environ) == -1)
{
perror("Error:");
return (1); /* Return a non-zero value to indicate failure */
}

/* This part of the code will not be reached if execve is successful */
printf("After execve\n");
return (0);
}

