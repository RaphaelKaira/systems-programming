// Write a program that reads three integers and prints the largest one.
// Solution:
#include <stdio.h>

int main() {
    int num1, num2, num3;
    printf("Enter three integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    int largest = num1;
    if (num2 > largest) largest = num2;
    if (num3 > largest) largest = num3;

    printf("The largest number is: %d\n", largest);
    return 0;
}
