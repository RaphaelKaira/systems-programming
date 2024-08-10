//Question:Write a program that reads a text file line by line and prints each line to the console.

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000
/**
 * It is used to specify the maximum length of a line that can be read from the file. 
 * By defining it this way, you can easily change the maximum line length in one place if needed.
 */

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: print lines [filename]\n");
        exit(0);
    }

    FILE *fpt;
    if ((fpt = fopen(argv[1], "r")) == NULL) {
        printf("Unable to open %s for reading\n", argv[1]);
        exit(0);
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fpt) != NULL) {
        printf("%s", line);
    }

    fclose(fpt);
    return 0;
}
/*
fgets(line, sizeof(line), fpt): Reads a line from the file into the line buffer. sizeof(line) ensures that up to MAX_LINE_LENGTH characters are read, including the null terminator. 
fgets stops reading when it encounters a newline character, end-of-file (EOF), or when the buffer is full.
*/