//Question:Write a program that creates a child process using fork, waits for the child process to finish using wait, and prints a message when the child process exits.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == -1) {
        perror("Error creating child process");
        return 1;
    }

    if (pid == 0) {
        printf("Child process (PID: %d) is running...\n", getpid());
        sleep(2); // Simulate some work
        printf("Child process (PID: %d) is exiting...\n", getpid());
        _exit(0);
    } else {
        printf("Parent process (PID: %d) waiting for child to exit...\n", getpid());
         wait(NULL);
        printf("Child process has exited. Parent process (PID: %d) is continuing...\n", getpid());
    }
    return 0;
}