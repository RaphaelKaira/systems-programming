//Question:Write a program that reads a text file and converts all the text to uppercase, then prints the result to the console.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: toupper [filename]\n");
        exit(0);
    }

    FILE *fpt;
    if ((fpt = fopen(argv[1], "r")) == NULL) {
        printf("Unable to open %s for reading\n", argv[1]);
        exit(0);
    }

    char c;
    while ((c = fgetc(fpt)) != EOF) {
        putchar(toupper(c));
    }
     fclose(fpt);
    return 0;
}
/**
 * The putchar() function in C is used to output a single character to the standard output (usually the terminal or console). 
 * FORMAT: int putchar(int char);
   * char: This is the character to be printed. It is passed as an integer value, but it represents the ASCII value of the character to be output.
 */