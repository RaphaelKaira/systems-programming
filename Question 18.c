// Question 18
// Program to write a string entered by the user to a file.
#include <stdio.h>

int main() {
    char str[100];  // Declare a character array to store the string
    FILE *file;  // Declare a file pointer

    printf("Enter a string: ");  // Prompt the user to enter a string
    scanf("%s", str);  // Read the string from the user and store it in 'str'

    file = fopen("output.txt", "w");  // Open a file named "output.txt" in write mode
    if (file == NULL) {  // Check if the file could not be opened for writing
        printf("Could not open file for writing\n");  // Print an error message if the file cannot be opened
        return 1;  // Return 1 to indicate an error
    }

    fprintf(file, "%s", str);  // Write the string to the file
    fclose(file);  // Close the file

    printf("String written to output.txt\n");  // Inform the user that the string has been written to the file
    return 0;  // Return 0 to indicate successful completion
}
