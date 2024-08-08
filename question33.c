//Question:Write a program that reads a series of integers from a file and calculates their average. Assume the numbers are separated by whitespace.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: average [filename]\n");
        exit(0);
    }

    FILE *fpt;
    if ((fpt = fopen(argv[1], "r")) == NULL) {
        printf("Unable to open %s for reading\n", argv[1]);
        exit(0);
    }

    int num, count = 0;
    double sum = 0.0;

    while (fscanf(fpt, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    fclose(fpt);

    if (count == 0) {
        printf("No numbers found.\n");
    } else {
        printf("Average: %.2f\n", sum / count);
    }
    
    return 0;
}