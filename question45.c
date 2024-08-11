#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_RESOURCES 3

sem_t semaphore; // Declare a semaphore

void* thread_function(void* arg) {
    sem_wait(&semaphore); // Decrease the semaphore value (acquire a resource)
    printf("Thread %ld acquired a resource.\n", (long)arg);

    // Simulate work
    sleep(1);

    printf("Thread %ld releasing the resource.\n", (long)arg);
    sem_post(&semaphore); // Increase the semaphore value (release the resource)

    return NULL;
}

int main() {
    pthread_t threads[5];

    // Initialize the semaphore with MAX_RESOURCES
    sem_init(&semaphore, 0, MAX_RESOURCES);

    for (long i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void*)i);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the semaphore
    sem_destroy(&semaphore);

    return 0;
}

/**
 * Semaphores are synchronization tools used in concurrent programming to control access to shared resources and coordinate the execution of processes or threads. 
 * They help manage resources in a multi-threaded or multi-process environment, preventing race conditions and ensuring data consistency.
 */