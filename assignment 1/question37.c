//Question:Write a program that appends text provided by the user to the end of a file.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: append [filename]\n");
        exit(0);
    }

    FILE *fpt;
    if ((fpt = fopen(argv[1], "a")) == NULL) {
        printf("Unable to open %s for appending\n", argv[1]);
        exit(0);
    }

    char text[1000];
    printf("Enter text to append (end with Ctrl+D):\n");
    while (fgets(text, sizeof(text), stdin) != NULL) {
        fputs(text, fpt);
    }

    fclose(fpt);
    return 0;
}
//The Ctrl+D sequence is used to indicate the end-of-file (EOF) when entering input from the terminal in a Unix-like operating system (including Linux and macOS). 
/**
 * fputs() function in C is used to write a string to a specified file stream.
 * FORMAT: int fputs(const char *str, FILE *stream);
  * str: A pointer to the string to be written. The string should be null-terminated.
  * stream: A pointer to a FILE object that specifies the output stream where the string will be written. This can be a file opened with fopen(), stdout for standard output, or other file streams.
 * fputs() returns a non-negative integer on success.If an error occurs, it returns EOF (End Of File).

 */