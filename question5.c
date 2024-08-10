//Question:Write a program that creates a new directory named "testdir" using a system call. Check if the directory was successfully created and print an appropriate message.

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    if (mkdir("testdir", 0755) == -1) { //0755: Sets the directory permissions.
        perror("Error creating directory");
        return 1;
    }
    printf("Directory created successfully\n");
    return 0;
}

/**
 * Syntax: mkdir(const char *pathname, mode_t mode);
  * pathname: The path of the directory to be created. It can be an absolute or relative path.
  * mode: The permissions to set for the newly created directory. This is typically specified using octal notation.
 * Return values: 
  * 0: Success. The directory was created successfully.
  * -1: Failure. An error occurred. The global variable errno is set to indicate the specific error.
 */