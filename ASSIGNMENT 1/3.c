//PROGRAM RO SEARCH AN ELEMENT IN AN A ARRAY  USING DYNAMIC MEMORY ALLOCATION 
  #include <stdio.h>
  #include <stdlib.h>

  int main() {
    int *arr, size, element, found = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory dynamically for the array
    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &element);

    // Search for the element
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Element found at index %d\n", i);
    } else {
        printf("Element not found\n");
    }

    // Free the allocated memory
    free(arr);

    return 0;
}
