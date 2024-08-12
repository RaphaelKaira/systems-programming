//Question:Write a C program that reads a string from the user and prints it.
#include <stdio.h>
#include <errno.h>

int main() {
    char str[100];


    printf("Enter a string: ");
    fgets(str, 100,"notice.txt");

    printf("You entered: %s", str);

    return 0;
}

/*
//Read string from file.
int main() {
    FILE *file;
    char str[100];

    // Open the file "notice.txt" for reading
    file = fopen("notice.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read a line from the file
    if (fgets(str, sizeof(str), file) != NULL) {
        printf("Read from file: %s", str);
    } else {
        printf("Error reading from file or file is empty.\n");
    }

    // Close the file
    fclose(file);

    return 0;
}
*/

/**
 * fgets function is used to read a string from a file (or from standard input if the file is stdin).
 * FORMAT: char *fgets(char *str, int n, FILE *stream);
    * str: Pointer to an array where the read string will be stored.
    * n: Maximum number of characters to read, including the null terminator.
    * stream: Pointer to the file from which to read, typically stdin for standard input.
 * Reads  a line until a newline character is encountered, the end-of-file (EOF) is reached, or n-1 characters are read (whichever comes first). It then null-terminates the string.
 * Retains whitespace characters, including spaces and tabs.
 * Protects against buffer overflow by limiting the number of characters read to n-1.
 * NOTE: fgets() reads a line from the file until it encounters a newline character, EOF, or the buffer size limit. It includes the newline character in the buffer if it is read before reaching the buffer size limit.
*/

//CODE using Scanfs
/*
int main() {
    char str[100];  // Declare a char array to store the input string

    printf("Enter a string: ");  // Prompt the user to enter a string
    scanf("%99s", str);          // Read input from standard input (stdin) into the array 'str'

    printf("You entered: %s\n", str);  // Print the entered string

    return 0;  // Return 0 to indicate successful execution
}
*/


/**
 * scanf function is used to read formatted input from the standard input (stdin).
 * FORMAT: int scanf(const char *format, ...);
   * format: A string specifying how to interpret the input. It can contain format specifiers such as %d for integers, %s for strings, etc.
 * Formatted Input: Reads input according to the specified format. Each format specifier matches a corresponding argument in the function call.
 * Whitespace Handling: Stops reading a string at whitespace, making it unsuitable for inputs containing spaces without special handling.
 * Potentially Unsafe: Can lead to buffer overflow if not properly managed (e.g., using %s without specifying a maximum field width).
 */


/**
 * stdin stands for "standard input." It is one of the three standard I/O streams that are automatically opened when a program starts:
    * Standard Input (stdin): Used to get input from the user, typically via the keyboard.
    * Standard Output (stdout): Used to send output to the display, typically the terminal or console.
    * Standard Error (stderr): Used to send error messages to the display, typically the terminal or console.
 * These streams are part of the standard library and are included in the stdio.h header file. stdin is a FILE pointer, which represents the standard input stream.
 * You can run your program and redirect stdin from this file: ./a.out < input.txt
 * In this case, the program will read the string and number from input.txt as if they were entered via the keyboard.
 */