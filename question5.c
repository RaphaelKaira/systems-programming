//Question: Write a C program that writes user input to a file and then reads from the file and prints its content.
#include <stdio.h>

int main() {
   
    FILE *fptr;
    char filename[100], str[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    fptr = fopen(filename, "w");

    if (fptr == NULL) {
        printf("Cannot open file \n");
        return 1;
    }

    printf("Enter a string to write to the file: ");
    getchar(); // consume the newline character left in the input buffer by the previous scanf function. 
    fgets(str, 100, stdin);

    fprintf(fptr, "%s", str);
    fclose(fptr);

    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Cannot open file \n");
        return 1;
    }

    printf("Content of the file:\n");
    while (fgets(str, 100, fptr) != NULL) {
        printf("%s", str);
    }

    fclose(fptr);
    return 0;
}
/**
  * FILE *fptr
     * a declaration of a pointer to a FILE structure.
     * This pointer is used to handle file operations such as opening, reading, writing, and closing files. 
     *  The FILE structure is defined in the standard library (stdio.h) and represents a file stream.
*/

/*
fopen() is used to open a file. Takes a pointer and mode as parameter.Returns a FILE pointer on success or null on faliure.
Modes:
    • ‘r’: Open text file for reading. The stream is positioned at the beginning of the file.
    • ‘r+’: Open for reading and writing. The stream is positioned at the beginning of the file.
    • ‘w’: Truncate file to zero length(remove existing text) or create text file for writing. The stream is positioned at the beginning of the file.
    • ‘w+’: Open for reading and writing. The file is created if it does not exist, otherwise it is truncated. The stream is positioned at the beginning of the file.
    • ‘a’: Open for appending (writing at end of file). The file is created if it does not exist. The stream is positioned at the end of the file.
    • ‘a+’: Open for reading and appending (writing at end of file). The file is created if it does not exist. The initial file position for reading is at the beginning of the file, but output is always appended to the end of the file.

fclose() function first flushes the stream opened by fopen() and then closes the underlying descriptor.
Upon successful completion this function returns 0 else end of file (eof) is returned. In case of failure,undefined.
*/

/** 
WHAT IS  AN INPUT BUFFER?
an input buffer is a temporary storage area used to hold data read from an input source, such as the keyboard or a file, before it is processed by the program.
Therefore:
After using scanf("%s", filename), the input buffer contains a newline character (\n) that was entered when the user pressed the Enter key. 
The scanf function does not consume this newline character, leaving it in the input buffer.
When you subsequently use fgets to read a string from the standard input, fgets would encounter this newline character and might not work as expected if it is still in the buffer.

WHAT IS  A STREAM?
* a stream is an abstraction that represents a sequence of data flowing to or from a program. 
* Streams allow for standardized input and output operations, abstracting away the details of how data is actually handled.
*/