//Question:Write a C program that reads a list of numbers from a file and calculates their average.
#include <stdio.h>

int main() {
    FILE *fptr;
    char filename[100];
    int num, count = 0;
    double sum = 0.0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Cannot open file \n");
        return 1;
    }
     while (fscanf(fptr, "%d", &num) != EOF) {
        sum += num;
        count++;
    }

    fclose(fptr);

    if (count == 0) {
        printf("No numbers found in the file.\n");
    } else {
        printf("Average: %.2f\n", sum / count);
    }

    return 0;
}
/**
 * The fscanf function in C is used for reading formatted input from a file stream. 
 * It operates similarly to scanf, but instead of reading from the standard input (stdin), it reads from a file specified by a FILE * pointer.
 * FORMAT: int fscanf(FILE *stream, const char *format, ...);
   * FILE *stream: A pointer to a FILE object that identifies the input stream from which data is to be read. This stream must be associated with an open file.
   * const char *format: A format string that specifies how the input data should be interpreted. It consists of format specifiers, conversion characters, and optional white space.
   * ... : A variable number of pointers to variables where the read data will be stored. Each format specifier in the format string corresponds to one of these pointers.
 * On Success: Returns the number of input items successfully matched and assigned. This count can be less than the number of format specifiers if some items are not successfully matched.
 * On Failure or End-of-File: Returns EOF (usually defined as -1). This indicates an error or end-of-file condition.
 */