// Write a program that reads integers until the user enters a negative number and then prints the sum of all entered numbers (excluding the negative one).
// Solution:
#include <stdio.h>

int main() {
    int num, sum = 0;
    printf("Enter integers (negative number to end): ");
    while (1) {
        scanf("%d", &num);
        if (num < 0) break;
        sum += num;
    }
    printf("Sum of entered numbers: %d\n", sum);
    return 0;
}