//  Write a C program that appends user input to an existing file.//
#include <stdio.h>

int main() {
    FILE *fptr;
    char filename[100], str[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    fptr = fopen(filename, "a");

    if (fptr == NULL) {
        printf("Cannot open file \n");
        return 1;
    }

    printf("Enter a string to append to the file: ");
    getchar(); // consume newline left by scanf
    fgets(str, 100, stdin);

    fprintf(fptr, "%s", str);//"%s": The format specifier that tells fprintf to write a string.str: The string to be written to the file.
    fclose(fptr);

    printf("Content appended to the file.\n");

    return 0;
}
// char filename[100]; declares an array to store the filename, allowing up to 99 characters plus a null terminator.
// char str[100]; declares an array to store the string that will be appended to the file, allowing up to 99 characters plus a null terminator.
// This line attempts to open the file in append mode ("a"). If the file does not exist, it will be created. If the file cannot be opened, fopen returns NULL.
// getchar(); consumes the newline character left in the input buffer by the previous scanf call to avoid immediate termination of fgets.
// fgets(str, 100, stdin); reads a line of text from the standard input (stdin) and stores it in the str array. It reads up to 99 characters plus the null terminator or until a newline character is encountered.
// This line writes the string stored in str to the file pointed to by fptr.
// fprintf is similar  to printf  used to write the formatted output of a file stream
// SYNTAX

// c

// int fprintf(FILE *stream, const char *format, ...);

// Parameters

//     FILE *stream: A pointer to a FILE object that identifies the output stream.
//     const char *format: A format string that specifies how to format the output. This string can include format specifiers (like %s, %d, etc.) that are replaced by the values specified in subsequent arguments.
//     ...: A variable number of arguments that correspond to the format specifiers in the format string.
// COMMON USES  of %s:

//     Printing a String:

//     c

// printf("The string is: %s\n", str);

// Here, %s is replaced by the content of the str array.

// Reading a String:

// c

// scanf("%s", str);

// This reads a sequence of characters from the input until a whitespace is encountered and stores it in the str array.

// Writing a String to a File:

// c

// fprintf(fptr, "%s", str);

// Here, %s writes the string str to the file stream fptr.