#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024

/*
* find_file - Search for a file in the provided path
* @filename: The name of the file to search for
* @path: The search path separated by ':'
*
* This function searches for the specified file in each directory
* within the provided path. It prints the full path of the file if found,
* otherwise, it prints a message indicating that the file was not found.
*/
void find_file(const char *filename, const char *path)
{
char full_path[MAX_PATH_LENGTH];
const char *delimiter = ":";

/* Tokenize the PATH using the delimiter */
char *token = strtok((char *)path, delimiter);
while (token != NULL)
{
/* Build the full path by concatenating the directory and filename */
snprintf(full_path, sizeof(full_path), "%s/%s", token, filename);

/* Check if the file exists at the current path */
if (access(full_path, F_OK) != -1)
{
printf("%s\n", (full_path));
return;
}

token = strtok(NULL, delimiter);
}

/* File not found in any directory in the PATH */
printf("%s not found in the PATH.\n", (filename));
}

/*
* main - Entry point of the program
* @argc: The number of command-line arguments
* @argv: An array of strings containing the arguments
*
* This function searches for the provided filenames in the system's PATH
* environment variable. It calls the find_file function for each filename.
* If no filenames are provided, it displays a usage message.
*/
int main(int argc, char *argv[])
{
/* Check if the filename(s) are provided */
if (argc <= 1)
{
printf("Usage: %s filename ...\n", (argv[0]));
return (1);
}

/* Get the current PATH from the environment variables */
const char *path = getenv("PATH");
if (path == NULL)
{
printf("PATH environment variable not found.\n");
return (1);
}

/* Iterate through the filenames and find them in the PATH */
for (int i = 1; i < argc; i++)
{
find_file((argv[i]), path);
}

return (0);
}

