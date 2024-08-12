//Question:Write a program that lists all files in the current directory using system calls.

#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) { //Reads each entry from the directory. readdir() returns a pointer to struct dirent for each entry.
            printf("%s\n", dir->d_name);
        }
        closedir(d); //Closes the directory stream when done.
    } else {
        perror("Error opening directory");
    }
    return 0;
}
/**
 * syntax: opendir(const char *name);
   * name: The name of the directory to open. It can be a relative or absolute path.
 * Return values: 
   * DIR: A pointer to a DIR structure representing the opened directory. This pointer is used in subsequent calls to readdir() and closedir().
   * NULL: If the directory cannot be opened (e.g., if it doesn’t exist or permission is denied), opendir() returns NULL. 
 
 * Syntax: readdir(DIR *dirp);
   * dirp: A pointer to a DIR structure obtained from opendir().
 * Return values: 
   * struct dirent: A pointer to a struct dirent representing the next directory entry. This contains information about the file or directory name.
   * NULL: If there are no more entries or if an error occurs.
 * Each call to readdir() returns information about a single directory entry.
 * The function returns a pointer to a struct dirent that holds information about the current entry.
 */
/**
 * The struct dirent is a structure used in C to represent a directory entry. 
 * It is defined in the <dirent.h> header file and is used with functions like readdir() to obtain information about files and directories within a directory.
 * struct dirent {
    ino_t d_ino;          // File serial number (inode number)
    off_t d_off;          // Offset to the next dirent
    unsigned short d_reclen; // Length of this record
    unsigned char d_type; // Type of file (e.g., directory, regular file)
    char d_name[256];     // Name of the file or directory
};
 */