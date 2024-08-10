//Question:Write a program that creates a child process using the fork system call and prints messages from both the parent and child processes.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork(); //used to create a new process by duplicating the calling process.
    if (pid == -1) {
        perror("Error creating child process");
        return 1;
    }

    if (pid == 0) {
        printf("This is the child process (PID: %d)\n", getpid()); //getpid() is used to obtain the process ID (PID) of the calling process.
    } else {
        printf("This is the parent process (PID: %d), child PID: %d\n", getpid(), pid);
    }
    return 0;
}

/**
 * pid_t: This type is used to represent process IDs in Unix-like operating systems. 
 * It is commonly used with functions that manage processes, such as fork(), getpid(), and wait()
 */
/**
 * Return values for Fork(void)
    * 0: Returned to the child process. This indicates that the current process is the child.
    * Positive Value: The process ID (PID) of the child process is returned to the parent process. This indicates that the current process is the parent.
    * -1: Indicates an error occurred, and no child process was created. In this case, errno is set to indicate the error.
*/