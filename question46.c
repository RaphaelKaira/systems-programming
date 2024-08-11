#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>

int main() {
    sem_t *mutex; //Declares a pointer to a semaphore object.
    mutex = sem_open("/mutex", O_CREAT, 0600, 1);

    for(int i = 0; i < 5; i++) {
        if(fork() == 0) {
            // Child process
            while(sem_wait(mutex) < 0); // Wait (acquire) semaphore
            // Critical section
            sem_post(mutex); // Signal (release) semaphore
            exit(0);
        }
    }

    for(int i = 0; i < 5; i++) {
        wait(NULL); // Wait for all child processes to finish
    }

    sem_close(mutex); // Close semaphore
    sem_unlink("/mutex"); // Remove semaphore

    return 0;
}

/**
 * The sem_open() function is used to create or open a named semaphore in POSIX systems.
 * Syntax: sem_t *sem_open(const char *name, int oflag, mode_t mode, unsigned int value);
    * name: The name of the semaphore. It must begin with a / and should be unique within the system. The name is used to identify the semaphore across different processes.
    * oflag: Flags that determine the behavior of sem_open(). Common flags include: 
        * O_CREAT: Create the semaphore if it does not exist.
        * O_EXCL: Used with O_CREAT to ensure that the semaphore is created only if it does not already exist (i.e., it will fail if the semaphore already exists).
    * mode (used with O_CREAT): The permissions for the semaphore, similar to file permissions.
    * value (used with O_CREAT): The initial value of the semaphore. 
 * Return values: 
    * On Success: Returns a pointer to the semaphore (sem_t *).
    * On Failure: Returns SEM_FAILED and sets errno to indicate the error.
 */

/**
 * sem_wait(): Decrements (locks) the semaphore, which may block the calling process or thread if the semaphore’s value is zero.
 * Syntax: int sem_wait(sem_t *sem);
 * Return values: 
    * On Success: Returns 0.
    * On Failure: Returns -1 and sets errno to indicate the error.
 */

/**
 * sem_post(): Increments (unlocks) the semaphore, potentially unblocking a waiting process or thread.
 * Syntax: int sem_post(sem_t *sem);
 * Return values: 
    * On Success: Returns 0.
    * On Failure: Returns -1 and sets errno to indicate the error.
 */

/**
 * sem_close(): Closes the semaphore descriptor.
 * Syntax: int sem_close(sem_t *sem);
 * Return values:
    * On Success: Returns 0.
    * On Failure: Returns -1 and sets errno to indicate the error.
 */

/**
 * sem_unlink(): Removes a named semaphore from the system.
 * int sem_unlink(const char *name);
 * Return values:
    * On Success: Returns 0.
    * On Failure: Returns -1 and sets errno to indicate the error.
 */