// PROGRAM TO ALLOCATE MEMORY USING MALLOC() AND THEN REALLOCATE THE PREVOIUSLY ALLOCATED MEMORY USING REALLOC().
  #include <stdio.h>
  #include <stdlib.h>

    int main() {
    int n, i;

    printf("Enter the initial number of elements: ");
    scanf("%d", &n);

    int *ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }

    printf("Original elements:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    int new_n;
    printf("Enter the new number of elements: ");
    scanf("%d", &new_n);

    ptr = (int *)realloc(ptr, new_n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    if (new_n > n) {
        printf("Enter %d more elements:\n", new_n - n);
        for (i = n; i < new_n; i++) {
            scanf("%d", &ptr[i]);
        }
    }

    printf("Elements after reallocation:\n");
    for (i = 0; i < new_n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr);

    return 0;
}
