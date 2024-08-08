//Question:Write a C program that counts the number of words in a text file.
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fptr;
    char filename[100], c;
    int word_count = 0, in_word = 0;
    /**
     * in_word is a flag indicating whether the current position is inside a word.
     * If it is whitespace, sets in_word to 0 (indicating that the character is outside a word).
     * if in_word is set to 1 indicates the start of a new word.
    */

    printf("Enter the filename: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Cannot open file \n");
        return 1;
    }

    //Reads each character from the file until the end of the file (EOF) is reached.
    while ((c = fgetc(fptr)) != EOF) {
        if (isspace(c)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            word_count++;
        }
    }

    fclose(fptr);

    printf("Word count: %d\n", word_count);

    return 0;
}
/**
 * The fgetc function in C is used to read a single character from a file stream.
 * FORMAT: int fgetc(FILE *stream);
   * FILE *stream: A pointer to a FILE object that identifies the input stream from which the character is to be read. 
   * This FILE object must be associated with an open file.
 * On Success: Returns the next character from the file as an unsigned char cast to an int. This value is promoted to an int to accommodate the special value EOF.
 * On Failure or End-of-File (EOF): Returns EOF (which is typically defined as -1). EOF is used to indicate the end of the file or an error.
*/
//isspace(c): Checks if the character c is a whitespace character (e.g., space, tab, newline).Comes from the <ctype.h> header.