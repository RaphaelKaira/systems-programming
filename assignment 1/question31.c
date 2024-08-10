//Question:Write a program that reads a text file and counts the number of words in it. Assume words are separated by whitespace.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//here we specify the file when calling the a.out e.g ./a.out newfile.txt
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: wordcount [filename]\n");
        exit(0);
    }

    FILE *fpt;
    if ((fpt = fopen(argv[1], "r")) == NULL) {
        printf("Unable to open %s for reading\n", argv[1]);
                exit(0);
    }

    int words = 0;
    int in_word = 0;
    char c;

    while ((c = fgetc(fpt)) != EOF) {
        if (isspace(c)) {
            if (in_word) {
                words++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }

    if (in_word) words++;  // Count the last word if it exists

    fclose(fpt);

    printf("Number of words: %d\n", words);
    return 0;
}

/**
 * int main(int argc, char *argv[]): This form of main allows your program to accept command-line arguments.
   * argc (Argument Count): This integer parameter represents the number of command-line arguments passed to the program, including the program's name itself. argc is always at least 1 because the first argument is the program's name.
   * argv (Argument Vector): This is an array of strings (character pointers) representing the command-line arguments. Each element in argv is a pointer to a null-terminated string. argv[0] is the name of the program, and argv[1] through argv[argc-1] are the additional command-line arguments passed to the program. 
 */