//Question:Write a program that replaces the current process with a new program using the execlp system call. For example, replace it with the ls command.

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Executing ls command...\n");
    execlp("ls", "ls", "-l", (char *)NULL); //used to replace the current process image with a new process image. 
    perror("Error executing ls");
    return 1;
}
/**
 * syntax: int execlp(const char *file, const char *arg0, ..., (char *)NULL);
    * file: The name of the file to execute. It is typically the program you want to run.
    * arg0: The name of the program being executed, conventionally the same as file. This is the first argument to the new program.
    * Additional Arguments: The arguments to the program being executed, with each argument being passed separately.
    * (char *)NULL: A null pointer indicating the end of the argument list.
 * Return values: 
    * 0: Not returned; if execlp() is successful, it does not return to the original program. The new program takes over the process.
    * -1: On failure, execlp() returns -1, and errno is set to indicate the error.
 */