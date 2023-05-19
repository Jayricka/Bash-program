#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * @ac: The number of command line arguments
 * @av: An array of strings containing the command line arguments
 *
 * Return: 0 on success
 *
 */
int main(int ac, char *av[])
{
int i;

for (i = 1; i < ac; i++)
{
printf("%s", av[i]);
printf("\n");
}

return (0);

}

