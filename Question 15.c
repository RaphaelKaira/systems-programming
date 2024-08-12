// Question 15
// Program to read a line of text from the user and print it.
#include <stdio.h>

int main() {
    char str[100];  // Declare a character array (string) to store the user's input
    printf("Enter a line of text: ");  // Prompt the user to enter a line of text
    fgets(str, sizeof(str), stdin);  // Read the entire line of text from the user and store it in 'str'
    printf("You entered: %s", str);  // Print the value of 'str'
    return 0;  // Return 0 to indicate successful completion
}
