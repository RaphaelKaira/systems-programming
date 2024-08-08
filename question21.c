//Write a program that reads a string from the user and prints it back to the user.
//Solution:
#include <stdio.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    printf("You entered: %s", str);
    return 0;
}