#include <stdio.h>

int main() {
    float num; // declares a floating point variable to store decimal numbers.
    printf("Enter a floating-point number: ");
    scanf("%f", &num);
    printf("You entered: %.2f\n", num);// Prints the floating-point number with 2 decimal places. %.2f tells the program to format the number to 2 decimal places. 
    return 0;
}
