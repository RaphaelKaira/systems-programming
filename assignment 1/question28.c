// Write a program that reads a string and prints its reverse.
// Solution:
#include <stdio.h>
#include <string.h>//string.h is included for string handling functions (strlen).

int main() {
    char str[100];
    int len, i;//len will store the length of the string, and i will be used as a loop index.
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    len = strlen(str);
    printf("Reversed string: ");
    for (i = len - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    return 0;
}
// fgets(str, 100, stdin); reads up to 99 characters from the standard input (stdin) and stores them in str. It also includes the newline character if the input is shorter than 99 characters.