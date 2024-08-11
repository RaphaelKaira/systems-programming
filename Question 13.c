#include <stdio.h>

int main() {
    char str[100];//Declares a character array (string) of size 100 to store the user's input.
    printf("Enter a string: ");
    scanf("%s", str);// Reads a string entered by the user. %s is the format specifier for strings.
    printf("You entered: %s\n", str);// rints the string that the user entered.
    return 0;
}
