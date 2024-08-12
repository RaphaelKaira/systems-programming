// Question 19
// Program to read integers from a file and print their sum.
#include <stdio.h>

int main() {
    FILE *file;  // Declare a file pointer
    int num, sum = 0;  // Declare an integer 'num' to store each number read from the file, and 'sum' to store the sum of the numbers

    file = fopen("numbers.txt", "r");  // Open a file named "numbers.txt" in read mode
    if (file == NULL) {  // Check if the file could not be opened
        printf("Could not open file numbers.txt\n");  // Print an error message if the file cannot be opened
        return 1;  // Return 1 to indicate an error
    }

    while (fscanf(file, "%d", &num) != EOF) {  // Read integers from the file until the end of file (EOF) is reached
        sum += num;  // Add the value of 'num' to 'sum'
    }

    fclose(file);  // Close the file
    printf("Sum of integers in the file: %d\n", sum);  // Print the sum of the integers
    return 0;  // Return 0 to indicate successful completion
}
