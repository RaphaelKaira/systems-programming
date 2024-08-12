/*Question: Write a C program that reads a text file and prints its content to the screen.*/
#include <stdio.h>

int main() {
    FILE *fptr;
    char filename[100], c;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Cannot open file \n");
        return 1;
    }

    /*c = fgetc(fptr);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fptr);
    }
    */
   while((c=fgetc(fptr)) != EOF){
        printf("%c",c);
   }

    fclose(fptr);
    return 0;
}
// FILE *fptr; declares a file pointer to handle file operations.
// char filename[100]; declares an array to store the filename, allowing up to 99 characters plus a null terminator.
// char c; declares a character variable to store each character read from the file.
// printf("Enter the filename: "); prompts the user to enter the filename.
// scanf("%s", filename); reads the filename entered by the user and stores it in the filename array.
// This line attempts to open the file in read mode ("r"). If the file cannot be opened (e.g., it doesn't exist), fopen returns NULL.
// c = fgetc(fptr); reads a character from the file.
// The while loop continues as long as the character read is not EOF (End Of File).
// printf("%c", c); prints the character to the screen.
// c = fgetc(fptr); reads the next character from the file.
