#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */
int main(void)
{
	printf("Max process ID: %d\n", (int)getpid());
		return (0);
}

