// Question: Write a C program that reads the content of a file and prints it in reverse order.
#include <stdio.h>
#include <stdlib.h>//stdlib.h is included for memory allocation functions like malloc and free.

int main() {
    FILE *fptr;
    char filename[100];
    long file_size;//long file_size; will store the size of the file.
    char *buffer;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Cannot open file \n");
        return 1;
    }

    fseek(fptr, 0, SEEK_END);//fseek(fptr, 0, SEEK_END); moves the file pointer to the end of the file.
    file_size = ftell(fptr);//file_size = ftell(fptr); gets the current position of the file pointer (which is the size of the file in bytes) and stores it in file_size.
    fseek(fptr, 0, SEEK_SET);//fseek(fptr, 0, SEEK_SET); moves the file pointer back to the beginning of the file.

    buffer = (char*)malloc(file_size + 1);//buffer = (char*)malloc(file_size + 1); allocates enough memory to hold the file content plus one additional byte for the null terminator.
    fread(buffer, 1, file_size, fptr);//fread(buffer, 1, file_size, fptr); reads the file content into the buffer.
    buffer[file_size] = '\0';//buffer[file_size] = '\0'; adds a null terminator at the end of the buffer to treat it as a string.

    fclose(fptr);

    printf("Reversed content:\n");
    for (long i = file_size - 1; i >= 0; i--) {
        printf("%c", buffer[i]);
    }
    printf("\n");

    free(buffer);
    return 0;
}
// long Data Type

//     Definition: long is a data type in C that is used to represent integer values. It typically provides more storage than the standard int data type. The exact size of long can vary depending on the system and compiler, but it is usually at least 32 bits (4 bytes) on most platforms.

//     Purpose: The long data type is often used when you need to store larger integer values that might exceed the range of an int. For example, on many systems, a long can hold values from -2,147,483,648 to 2,147,483,647, which is useful for representing large numbers like file sizes or large counts.