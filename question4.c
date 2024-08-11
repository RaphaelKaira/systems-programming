//Question:Write a program that retrieves and prints the size and permissions of "example.txt" using the stat system call.
#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat fileStat; //used to store information about a file obtained via the stat() function.
    if (stat("example.txt", &fileStat) == -1) {
        perror("Error getting file status");
        return 1;
    }

    printf("File size: %ld bytes\n", fileStat.st_size);
    printf("Permissions: %o\n", fileStat.st_mode & 0777);//& 0777 masks out everything except the permission bits.
    return 0;
}

/**
 * struct stat is a structure used to store information about a file. It typically includes:
    * st_mode: File mode (permissions and file type).
    * st_size: Size of the file in bytes.
    * st_uid: User ID of the file owner.
    * st_gid: Group ID of the file owner.
    * st_atime: Time of last access.
    * st_mtime: Time of last modification.
    * st_ctime: Time of last status change.
 */
/**
 * Syntax: stat(const char *pathname, struct stat *statbuf);
    * pathname: Path to the file whose status is to be retrieved.
    * statbuf: Pointer to a struct stat where the file status information will be stored.
 * Retrieves the status information of the specified file and populates the statbuf structure with this information.
 * Return value: 
    * 0: Success. The file status information is stored in statbuf.
    * -1: Failure. An error occurred, and errno is set to indicate the error.
 */
/**
 * %ld: This format specifier is used to print a long integer.
 * %o: This format specifier is used to print an unsigned integer in octal (base-8) format
 */
/**
 * n C, file permissions are often represented using octal notation.
    * 0000: No permissions.Meaning: No read, write, or execute permissions.
    * 0400: Read permission for the owner.Meaning: Only the owner can read the file.
    * 0200: Write permission for the owner.Meaning: Only the owner can write to the file.
    * 0100: Execute permission for the owner.Meaning: Only the owner can execute the file.
    * 0600: Read and write permissions for the owner.Meaning: The owner can read and write the file, but others have no permissions.
    * 0700: Read, write, and execute permissions for the owner.Meaning: The owner can read, write, and execute the file, but others have no permissions.
    * 0070: Read, write, and execute permissions for the group.Meaning: Members of the file's group can read, write, and execute the file.
    * 0007: Read, write, and execute permissions for others.Meaning: Anyone can read, write, and execute the file.
    * 0644: Read and write permissions for the owner, read-only for group and others.Meaning: The owner can read and write the file, while others can only read it.
    * 0755: Read, write, and execute permissions for the owner, read and execute permissions for group and others.Meaning: The owner can read, write, and execute the file, while others can read and execute it.
    * 0777: Full permissions for everyone (read, write, and execute).Meaning: The owner, group, and others can read, write, and execute the file.
 */
/*
chmod() is used to change permissions for a file in a unix machine. Ex: chmod(540 test.txt)
Understanding Permissions:
    Owner: The user who owns the file.
    Group: Users who are members of the file's group.
    Others: All other users.

Each octal digit represents a combination of read (4), write (2), and execute (1) permissions:
    Read (r): 4 (octal)
    Write (w): 2 (octal)
    Execute (x): 1 (octal)

The octal value is a sum of these permissions. For example, 0755 translates to:
    Owner: 7 (read 4 + write 2 + execute 1)
    Group: 5 (read 4 + execute 1)
    Others: 5 (read 4 + execute 1)
These permissions are used to control access to files and directories in Unix-like operating systems.
*/