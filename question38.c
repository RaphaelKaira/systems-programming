//Question:Write a program that reads a file and replaces all instances of a specified word with another word, then writes the modified content to a new file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

//This function replaces all occurrences of word with replacement in the string src and stores the result in result.
/**
 * steps:
 * Find Occurrences: Uses strstr() to locate the first occurrence of word in src.
 * Copy and Replace:
 * Copy Prefix: Copies the part of src before the found word into temp.
 * Append Replacement: Uses sprintf() to append the replacement word and the rest of the original src after the found word.
 * Update src: Copies the modified temp back to src.
 * Set Result: Copies the final modified src to result.
 */
void replace_word(const char *src, const char *word, const char *replacement, char *result) {
    char *pos, temp[MAX_LINE_LENGTH];
    int len = strlen(word);

    while ((pos = strstr(src, word)) != NULL) {
        strncpy(temp, src, pos - src);
        temp[pos - src] = '\0';
        sprintf(temp + (pos - src), "%s%s", replacement, pos + len);
        strcpy(src, temp);
    }
    strcpy(result, src);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: replace [filename] [word] [replacement]\n");
             exit(0);
    }

    FILE *fpt, *new_fpt;
    if ((fpt = fopen(argv[1], "r")) == NULL) {
        printf("Unable to open %s for reading\n", argv[1]);
        exit(0);
    }

    char new_filename[100];
    snprintf(new_filename, sizeof(new_filename), "new_%s", argv[1]);
    if ((new_fpt = fopen(new_filename, "w")) == NULL) {
        printf("Unable to open %s for writing\n", new_filename);
        fclose(fpt);
        exit(0);
    }

    char line[MAX_LINE_LENGTH], result[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fpt) != NULL) {
        replace_word(line, argv[2], argv[3], result);
        fputs(result, new_fpt);
    }

    fclose(fpt);
    fclose(new_fpt);
    return 0;
}

/**
 * strlen() function counts the number of characters in the string until it encounters the null terminator '\0'. It does not include the null terminator in the count.. 
 * FORMAT: strlen(const char *str);
  * str: A pointer to the null-terminated string whose length you want to determine.
 * strlen() returns the number of characters in the string, not including the null terminator '\0'.
*/

/**
 * The strstr() function in C is used to locate the first occurrence of a substring within a larger string.
 * FORMAT: char *strstr(const char *haystack, const char *needle);
  * haystack: A pointer to the null-terminated string in which to search for the substring.(String in which to find a specified word)
  * needle: A pointer to the null-terminated substring that you want to find within haystack.(specified word)
 * strstr() returns a pointer to the first occurrence of the substring needle within the string haystack.
 * If the substring needle is found, the function returns a pointer to the beginning of the first occurrence in haystack.
 * If the substring needle is not found, the function returns NULL.
*/

/**
 * The strncpy() function in C is used to copy a specified number of characters from one string to another.
 * FORMAT: strncpy(char *dest, const char *src, size_t n);
  * dest: A pointer to the destination buffer where the copied string will be stored.
  * src: A pointer to the source string to be copied.
  * n: The maximum number of characters to copy from the source string.
 * strncpy() returns a pointer to the destination string dest.
 */

/**
 * The sprintf() function in C is used to format and store a series of characters and values into a string.
 * FORMAT: sprintf(char *str, const char *format, ...);
  * str: A pointer to the character array (string) where the formatted output will be stored.
  * format: A format string that specifies how to format the subsequent arguments. It includes format specifiers (e.g., %d, %s) that define how to convert and display the values.
  * ... : Additional arguments that are formatted according to the format string.
 * sprintf() returns the number of characters written to the string str, excluding the null terminator.If an error occurs, it returns a negative value.
*/

/**
 * The strcpy() function in C is used to copy a null-terminated string from one location to another. 
 * FORMAT: strcpy(char *dest, const char *src);
  * dest: A pointer to the destination buffer where the copied string will be stored. The buffer must be large enough to hold the source string and the null terminator.
  * src: A pointer to the null-terminated source string that you want to copy.
 * strcpy() returns a pointer to the destination string dest.
 */