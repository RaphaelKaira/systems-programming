//Question:Write a program that writes the string "Hello, World!" to "example.txt" using system calls.
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open("example.txt", O_WRONLY | O_TRUNC);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    const char *message = "Hello, World!\n"; //Declares a pointer message that points to a constant string "Hello, World!\n"
    if (write(fd, message, strlen(message)) == -1) {
        perror("Error writing to file");
    }

    close(fd);
    return 0;
}
/**
 * Syntax: write(int fd, const void *buf, size_t count);
    * fd: File descriptor where the data will be written.
    * buf: Pointer to the buffer containing the data to be written.
    * count: Number of bytes to write from the buffer.
 * Return values: 
    * Positive Value: Number of bytes successfully written.
    * 0: The write operation was successful but no bytes were written (usually not expected for regular files).
    * -1: An error occurred. The specific error can be determined by checking the errno variable.
 */