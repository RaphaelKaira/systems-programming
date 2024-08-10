//Question:Write a program that uses a system call to create a new file named "example.txt". Check if the file was successfully created and print an appropriate message.
#include <stdio.h>
#include <fcntl.h> //For file control options (e.g., O_CREAT, O_WRONLY).
#include <unistd.h> //For POSIX operating system API (e.g., close()).

int main() {
    int fd = open("example.txt", O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        perror("Error creating file");
        return 1;
    }
    printf("File created successfully\n");
    close(fd); //Closes the file descriptor, freeing up resources.
    return 0;
}
/**
 * open()
 * Syntax: int open(const char *pathname, int flags, mode_t mode);
    * pathname: The path to the file you want to open or create.
    * flags: Options specifying how to open the file (e.g., read, write, create).
    * mode: The permissions to set for the file if it is created (only relevant when O_CREAT is used).
 * if successful returns a file descriptor (a non-negative integer) else Returns -1 if an error occurs.
 */
/**
 * Flags: 
 * O_RDONLY: Open for read-only access.
 * O_RDWR: Open for both reading and writing.
 * O_WRONLY: Open the file for write-only access.
 * 
 * O_CREAT: If the file does not exist, it will be created.
 * O_TRUNC: Truncate the file to zero length if it already exists (used with O_WRONLY or O_RDWR).
 * O_APPEND: Append data to the end of the file (used with O_WRONLY or O_RDWR).
 * 
 * O_EXCL: When used with O_CREAT, it ensures that the file is created exclusively. If the file already exists, open() fails.
 * O_NONBLOCK: Open the file in non-blocking mode (useful for devices and pipes).
 * 
 * O_SYNC: Open the file for synchronous I/O. Writes are completed only after data is physically written to the storage device.
 * O_DSYNC: Similar to O_SYNC, but only affects data, not metadata.
 * O_NOATIME: Do not update the file's last access time on read operations.
 */
/**
 * Modes:
 * 0644: Owner can read/write; group and others can read.
 * 0666: All users can read and write.
 * 0600: Owner can read/write; no access for others.
 * 0755: Owner can read/write/execute; group and others can read/execute.
 */