#include <stdio.h>

int main() {
    FILE *file;
    char filename[100] = "output.txt";//char filename[100] = "output.txt";: A character array to store the filename. It is initialized with "output.txt".

    file = fopen(filename, "w");//fopen is used to open the file named output.txt in write mode ("w").

    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    fprintf(file, "Hello, World!\n");

    fclose(file);
    printf("Data written to file %s\n", filename);
    return 0;
}