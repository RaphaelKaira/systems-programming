//Question:Write a program that reads the contents of "example.txt" using system calls and prints the content to the console.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char buffer[100]; //This array will be used to temporarily hold data read from a file.
    ssize_t bytesRead; //Stores the number of bytes actually read. 
    while ((bytesRead = read(fd, buffer, sizeof(buffer)-1)) > 0) { 
        buffer[bytesRead] = '\0'; //Adds a null terminator at the end of the data read into the buffer to ensure it can be properly used as a C string.
        printf("%s\n", buffer);
    }

    if (bytesRead == -1) {
        perror("Error reading file");
    }

    close(fd);
    return 0;
}
/**
     * Reads up to sizeof(buffer) - 1 bytes from the file descriptor fd into the buffer
     * sizeof(buffer) - 1 is used to leave space for a null terminator (\0), which is added to make the buffer a valid C string.
 */
/**
 * ssize_t is a data type used for representing sizes of objects and counts of bytes. 
 * It is typically used for return values from functions like read() and write(), where it can represent both the number of bytes read or written and errors (if negative).
 */
/**
 * Syntax: read(int fd, void *buf, size_t count);
   * fd: File descriptor from which data is to be read.
   * buf: Pointer to the buffer where the read data will be stored.
   * count: Maximum number of bytes to read.
 * Reads up to count bytes from the file descriptor into the buffer.
 * Return values:
   * Positive Value: Number of bytes actually read.
   * 0: End of file (EOF) reached.
   * Negative Value: An error occurred (e.g., invalid file descriptor or read failure).
 */