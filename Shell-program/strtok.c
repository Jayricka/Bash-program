#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* split_string - Splits a string into an array of words.
*
* @str: The string to split.
* @delimiter: The delimiter used to separate words.
* @count: Pointer to an integer to store the count of words found.
*
* Return: The array of words on success, NULL on failure.
*/
char **split_string(char *str, const char *delimiter, int *count);

/**
* allocate_memory - Allocates memory for the words array.
*
* @count: The number of words to allocate memory for.
*
* Return: The allocated array of words on success, NULL on failure.
*/
char **allocate_memory(int count);

/**
* store_word - Stores a word in the words array.
*
* @words: The array of words.
* @word: The word to store.
* @index: The index where the word should be stored.
*
* Return: 1 on success, 0 on failure.
*/
int store_word(char **words, char *word, int index);

/**
* split_string - Splits a string into an array of words.
*
* @str: The string to split.
* @delimiter: The delimiter used to separate words.
* @count: Pointer to an integer to store the count of words found.
*
* Return: The array of words on success, NULL on failure.
*/
char **split_string(char *str, const char *delimiter, int *count)
{
char *str_copy = strdup(str);
if (str_copy == NULL)
return (NULL);

char *token;
char **words = NULL;
int word_count = 0;

token = strtok(str_copy, delimiter);

while (token != NULL)
{
words = allocate_memory(word_count + 1);
if (words == NULL)
{
free(str_copy);
return (NULL);
}

if (!store_word(words, token, word_count))
{
free(str_copy);
free(words[word_count]);
free(words);
return (NULL);
}

word_count++;
token = strtok(NULL, delimiter);
}

*count = word_count;
free(str_copy);
return (words);
}

/**
* allocate_memory - Allocates memory for the words array.
*
* @count: The number of words to allocate memory for.
*
* Return: The allocated array of words on success, NULL on failure.
*/
char **allocate_memory(int count)
{
char **words = realloc(NULL, sizeof(char *) * count);
if (words == NULL)
return (NULL);
return (words);
}

/**
* store_word - Stores a word in the words array.
*
* @words: The array of words.
* @word: The word to store.
* @index: The index where the word should be stored.
*
* Return: 1 on success, 0 on failure.
*/
int store_word(char **words, char *word, int index)
{
words[index] = strdup(word);
if (words[index] == NULL)
return (0);
return (1);
}

/**
* print_words - Prints an array of words.
*
* @words: The array of words to print.
* @count: The number of words in the array.
*/
void print_words(char **words, int count)
{
for (int i = 0; i < count; i++)
{
printf("%s\n", words[i]);
free(words[i]);
}
free(words);
}

/**
* main - Entry point of the program.
*
* Return: Always 0 on success.
*/
int main(void)
{
char *str = "splits a string and returns an array of each word of the string";
const char *delimiter = " ";
int count;
char **words = split_string(str, delimiter, &count);

if (words == NULL)
{
printf("Failed to split the string.\n");
return (1);
}

print_words(words, count);

return (0);
}

