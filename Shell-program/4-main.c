#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** split_string(char* str, const char* delimiter, int* count) {
    // Create a copy of the string
    char* str_copy = strdup(str);
    
    // Create a temporary pointer
    char* token;
    
    // Create an array to store the words
    char** words = (char**)malloc(sizeof(char*) * 100);
    
    // Use strtok to split the string
    token = strtok(str_copy, delimiter);
    int i = 0;
    while (token != NULL) {
        // Store the word in the array
        words[i++] = strdup(token);
        
        // Get the next word
        token = strtok(NULL, delimiter);
    }
    
    // Set the count variable
    *count = i;
    
    // Free the copy of the string
    free(str_copy);
    
    // Return the array of words
    return words;
}

int main() {
    char* str = "splits a string and returns an array of each word of the string";
    const char* delimiter = " ";
    int count;
    char** words = split_string(str, delimiter, &count);
    
    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }
    
    free(words);
    return 0;
}

