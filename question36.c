//Question:Write a program that counts the number of lines in a text file.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: countlines [filename]\n");
        exit(0);
    }

    FILE *fpt;
    if ((fpt = fopen(argv[1], "r")) == NULL) {
        printf("Unable to open %s for reading\n", argv[1]);
        exit(0);
    }

    int lines = 0;
    char c;
    while ((c = fgetc(fpt)) != EOF) {
        if (c == '\n') {
            lines++;
        }
    }

    fclose(fpt);

    printf("Number of lines: %d\n", lines);
    return 0;
}