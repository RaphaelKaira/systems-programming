//Question:Write a program that deletes the file "example.txt" using a system call.

#include <stdio.h>
#include <unistd.h>

int main() {
    if (unlink("example.txt") == -1) {
        perror("Error deleting file");
        return 1;
    }
    printf("File deleted successfully\n");
    return 0;
}

/**
 * The unlink() function in C is used to delete a file. 
 * It removes the file name from the filesystem and deallocates the file's inode if there are no more references to it (i.e., no other hard links or open file descriptors).
 * Syntax: unlink(const char *pathname);
    * pathname: A pointer to a null-terminated string representing the path of the file to be deleted. This can be an absolute or relative path.
 * Return values:
    * 0: On success, indicating that the file has been successfully deleted.
    * -1: On failure, indicating an error. The global variable errno is set to indicate the specific error.
 */