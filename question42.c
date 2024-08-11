#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initial allocation of memory for 5 integers
    int *array = (int *)malloc(5 * sizeof(int));
    if (array == NULL) {
        perror("Error allocating memory");
        return 1;
    }

    // Initialize the array
    for (int i = 0; i < 5; ++i) {
        array[i] = i + 1;
    }

    printf("Initial array:\n");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Resize memory to hold 10 integers
    int *new_array = (int *)realloc(array, 10 * sizeof(int));
    if (new_array == NULL) {
        perror("Error reallocating memory");
        free(array); // Free the old memory block
        return 1;
    }
    array = new_array; // Use the resized memory

    // Initialize new elements
    for (int i = 5; i < 10; ++i) {
        array[i] = i + 1;
    }

    printf("Resized array:\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(array);

    return 0;
}
/**
 * Malloc(): Allocates a block of memory on the heap and returns a pointer to the beginning of this block.
 * Syntax: void* malloc(size_t size);
    * size: The number of bytes to allocate.
 * Return values:
    * Returns a pointer to the allocated memory block.
    * Returns NULL if the allocation fails (e.g., due to insufficient memory).
 
 * Realloc(): Resizes a previously allocated memory block. It can expand or shrink the block.
 * Syntax: void* realloc(void* ptr, size_t new_size);
    * ptr: A pointer to the previously allocated memory block (can be NULL if expanding a NULL pointer).
    * new_size: The new size in bytes of the memory block.
 * Return values:
    * Returns a pointer to the newly allocated memory block. This pointer may be different from ptr if the block was moved.
    * Returns NULL if the reallocation fails. The original memory block remains unchanged if realloc fails.
 */