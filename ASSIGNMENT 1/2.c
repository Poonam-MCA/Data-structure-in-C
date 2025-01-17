//PROGRAM FOR ALLOCATING MEMORY USONG CALLOC() AND THEN REALLOCATING THEN ALLOCATING MEMORY USING REALLOC()
  #include <stdio.h>
  #include <stdlib.h>

   int main() {
    int *ptr, *new_ptr, size, new_size;

    printf("Enter the initial size of the array: ");
    scanf("%d", &size);

    // Allocate memory using calloc
    ptr = (int *)calloc(size, sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize the array elements
    for (int i = 0; i < size; i++) {
        ptr[i] = i + 1;
    }

    printf("Original array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Get the new size for reallocation
    printf("Enter the new size of the array: ");
    scanf("%d", &new_size);

    // Reallocate memory using realloc
    new_ptr = (int *)realloc(ptr, new_size * sizeof(int));
    if (new_ptr == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    // Initialize the new elements if the size has increased
    if (new_size > size) {
        for (int i = size; i < new_size; i++) {
            new_ptr[i] = i + 1;
        }
    }

    printf("Reallocated array elements:\n");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", new_ptr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(new_ptr);

    return 0;
}
