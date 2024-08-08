// Write a program that reads a file and prints its contents to the console.
// Solution:
#include <stdio.h>

int main() {
    FILE *file;
    char filename[100], ch;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
    return 0;
}