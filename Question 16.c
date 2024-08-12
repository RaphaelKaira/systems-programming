// Question 16
// Program to read an integer array of size 5 from the user and print the elements.
#include <stdio.h>

int main() {
    int arr[5];  // Declare an array of 5 integers to store the user's input
    printf("Enter 5 integers: ");  // Prompt the user to enter 5 integers
    for(int i = 0; i < 5; i++) {  // Loop to read each integer and store it in the array
        scanf("%d", &arr[i]);  // Read the integer and store it in 'arr[i]'
    }
    printf("You entered: ");  // Prepare to print the elements of the array
    for(int i = 0; i < 5; i++) {  // Loop to print each element of the array
        printf("%d ", arr[i]);  // Print the value of 'arr[i]'
    }
    printf("\n");  // Print a newline after printing all elements
    return 0;  // Return 0 to indicate successful completion
}
