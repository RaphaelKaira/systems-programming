//Question:Write a program that copies the contents of one file to another file.
#include <stdio.h>
#include <stdlib.h>

// takes two arguments when called: the file to copy from and the file to read to
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: copy [sourcefile] [destfile]\n");
        exit(0);
    }

    FILE *src, *dest;
    if ((src = fopen(argv[1], "r")) == NULL) {
        printf("Unable to open %s for reading\n", argv[1]);
        exit(0);
    }

    if ((dest = fopen(argv[2], "w")) == NULL) {
        printf("Unable to open %s for writing\n", argv[2]);
        fclose(src);
        exit(0);
    }

    char c;
    while ((c = fgetc(src)) != EOF) {
        fputc(c, dest);
    }

    fclose(src);
    fclose(dest);
    return 0;
}

/**
 * The fputc() function in C is used to write a single character to a specified file stream. 
 * It is similar to putchar(), but fputc() allows you to specify the file stream where the character should be written.
 * FORMAT: int fputc(int char, FILE *stream);
  * char: The character to be written. It is passed as an integer but represents the ASCII value of the character to be written to the file stream.
  * stream: A pointer to a FILE object that identifies the output stream (e.g., a file or stdout).
 * fputc() returns the character written as an unsigned char cast to an int, or EOF (End Of File) if an error occurs.
 */