#include <stdio.h>
#include <unistd.h>

/**
* main - PID
*
* Return: Always 0.
*/
int main(void)
{
pid_t pid_info;

pid_info = getpid();
printf("%u\n", pid_info);
return (0);
}
