// Question 20
// Program to read a character from the user and determine if it is a vowel or consonant.
#include <stdio.h>

int main() {
    char ch;  // Declare a character variable to store the user's input
    printf("Enter a character: ");  // Prompt the user to enter a character
    scanf(" %c", &ch);  // Read the character from the user and store it in 'ch'

    // Check if the character is a vowel (both lowercase and uppercase)
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
        printf("%c is a vowel.\n", ch);  // If it is a vowel, print that it is a vowel
    } else {
        printf("%c is a consonant.\n", ch);  // If it is not a vowel, print that it is a consonant
    }
    
    return 0;  // Return 0 to indicate successful completion
}
