// Write a program that reads a line of text and counts the number of vowels in it.
// Solution:
#include <stdio.h>
#include <ctype.h>//ctype.h is included for character handling functions (tolower).

int main() {
    char str[100];
    int i, count = 0;
    printf("Enter a string: ");
    fgets(str, 100, stdin);//fgets reads up to 99 characters from the standard input (stdin) and stores them in str. The 100th character is reserved for the null terminator ('\0').

    for (i = 0; str[i] != '\0'; i++) //str[i] != '\0' checks if the current character is not the null terminator, meaning there are more characters to process in the string.
    {
        if (tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || 
            tolower(str[i]) == 'o' || tolower(str[i]) == 'u') //    tolower(str[i]) is used to convert each character to lowercase before checking if it is a vowel.
    // This ensures that the comparison is case-insensitive, so both uppercase and lowercase vowels are counted.


            {
            count++;
        }
    }

    printf("Number of vowels: %d\n", count);
    return 0;
}
//The tolower function in C is used to convert an uppercase letter to its corresponding lowercase letter. It is part of the <ctype.h> library, which provides functions for character handling.
// Syntax

// c

// int tolower(int c);
// Parameters

//     c: The character to be converted. It should be an int that represents a character (usually obtained from a character variable).

// Return Value

//     If c is an uppercase letter (from 'A' to 'Z'): tolower returns the corresponding lowercase letter ('a' to 'z').
//     If c is not an uppercase letter: tolower returns the character unchanged.
