#include <stdio.h>
#include <unistd.h>

/**
 * a program that prints same ppid
*/
int main(void)
{
	pid_t pid = getpid();
	pid_t ppid = getppid();
	printf("pid: %d\nppid: %d\n", pid, ppid);
	return 0;
}
