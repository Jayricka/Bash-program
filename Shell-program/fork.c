#include <stdio.h>
#include <unistd.h>

/**
* main - fork example
*
* Return: Always 0.
*/
int main(void)
{
pid_t pid_info;
pid_t pid;

printf("Before fork\n");
pid = fork();
if (pid == -1)
{
perror("Error:");
return (1);
}
printf("After fork\n");
pid_info = getpid();
printf("My pid is %u\n", pid_info);
return (0);
}
