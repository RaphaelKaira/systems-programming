#include <stdio.h>

int main() {
    int num1, num2;// Declares two integer variables.
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);//Reads two integers entered by the user and stores them in num1 and num2.
    printf("Sum: %d\n", num1 + num2);//Calculates and prints the sum of num1 and num2.
    return 0;
}