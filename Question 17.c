// Question 17
// Program to read a file name from the user, open the file, and print its contents.
#include <stdio.h>

int main() {
    char filename[100];  // Declare a character array to store the file name
    char ch;  // Declare a character variable to store each character read from the file
    FILE *file;  // Declare a file pointer

    printf("Enter the file name: ");  // Prompt the user to enter the file name
    scanf("%s", filename);  // Read the file name from the user and store it in 'filename'

    file = fopen(filename, "r");  // Open the file in read mode
    if (file == NULL) {  // Check if the file could not be opened
        printf("Could not open file %s\n", filename);  // Print an error message if the file cannot be opened
        return 1;  // Return 1 to indicate an error
    }

    while ((ch = fgetc(file)) != EOF) {  // Read each character from the file until the end of file (EOF) is reached
        putchar(ch);  // Print the character
    }

    fclose(file);  // Close the file
    return 0;  // Return 0 to indicate successful completion
}
