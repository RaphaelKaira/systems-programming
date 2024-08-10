//Question:Write a program that reads the contents of a binary file and prints the hexadecimal representation of its content to the console.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: readbinary [filename]\n");
        exit(0);
    }

    FILE *fpt;
    if ((fpt = fopen(argv[1], "rb")) == NULL) {
        printf("Unable to open %s for reading\n", argv[1]);
        exit(0);
    }

    unsigned char buffer[16];
    // Declares a buffer array of 16 bytes to temporarily store data read from the file. 
    size_t bytes_read;
    //Variable to store the number of bytes actually read by fread().
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fpt)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
          printf("%02X ", buffer[i]);
        }
        printf("\n");
    }

    fclose(fpt);
    return 0;
}
/*
fread() & fwrite() are used for reading/writing data from/to the file opened by fopen function.
Takes the arguments:
  • pointer to buffer used for reading/writing the data.
  • data read/written is in the form of ‘nmemb’ elements each ‘size’ bytes long. 
  • the FILE stream pointer returned by the fopen() function
In case of success, fread/fwrite return the number of bytes actually read/written from/to the stream opened by fopen function. In case of failure, a lesser number of byes (then requested to read/write) is returned.

*/