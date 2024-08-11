#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 

int main() {
    mode_t old_umask = umask(022); // Set umask to 022 and get the old umask
    printf("Old umask: %o\n", old_umask);

    // Create a file with the new umask setting
    FILE *file = fopen("testfile.txt", "w");
    if (file) {
        fclose(file);
        printf("File created with new umask.\n");
    } else {
        perror("Error creating file");
    }

    return 0;
}

/**
 * umask (short for "user mask") is a function in Unix-like operating systems that sets the default permissions for newly created files and directories.
 * It works by defining which permissions should be masked (i.e., turned off) when files or directories are created.
 * The umask value is a 3-digit octal number (e.g., 022) that determines which permission bits should be removed.
 * umask subtracts permissions from the default permissions for newly created files and directories.
 */