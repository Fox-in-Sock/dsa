#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    arr = (int*)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input values for the array
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Print the array
    printf("The elements in the array are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(arr);
    printf("Memory has been freed.\n");

    return 0;
}
--------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory using calloc (initialized to zero)
    arr = (int*)calloc(n, sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input values for the array
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Print the array
    printf("The elements in the array are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Resize the array using realloc
    printf("Enter the new size of the array: ");
    scanf("%d", &n);

    arr = (int*)realloc(arr, n * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    // Input new elements if the array has been resized
    printf("Enter new elements for the resized array:\n");
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Print the resized array
    printf("The resized array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(arr);
    printf("Memory has been freed.\n");

    return 0;
}
-----------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr_malloc, *arr_calloc, *arr_realloc;
    int n, i, new_size;

    // malloc() - Allocating memory using malloc
    printf("Enter the number of elements for malloc array: ");
    scanf("%d", &n);

    arr_malloc = (int*)malloc(n * sizeof(int));  // Allocate memory

    if (arr_malloc == NULL) {
        printf("Memory allocation failed using malloc!\n");
        return 1;  // Exit if malloc fails
    }

    // Input values for arr_malloc
    printf("Enter %d elements for malloc array:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr_malloc[i]);
    }

    // Print malloc array
    printf("Elements in malloc array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr_malloc[i]);
    }
    printf("\n");

    // calloc() - Allocating memory using calloc (initialized to zero)
    printf("Enter the number of elements for calloc array: ");
    scanf("%d", &n);

    arr_calloc = (int*)calloc(n, sizeof(int));  // Allocate memory and initialize to 0

    if (arr_calloc == NULL) {
        printf("Memory allocation failed using calloc!\n");
        return 1;  // Exit if calloc fails
    }

    // Input values for arr_calloc
    printf("Enter %d elements for calloc array:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr_calloc[i]);
    }

    // Print calloc array
    printf("Elements in calloc array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr_calloc[i]);
    }
    printf("\n");

    // realloc() - Allocating memory using realloc (resizing the array)
    printf("Enter the new size for realloc array: ");
    scanf("%d", &new_size);

    arr_realloc = (int*)realloc(arr_malloc, new_size * sizeof(int));  // Resize using realloc

    if (arr_realloc == NULL) {
        printf("Memory reallocation failed using realloc!\n");
        return 1;  // Exit if realloc fails
    }

    // If new elements are added, input values for new resized array
    printf("Enter %d elements for realloc array (remaining elements will be initialized to 0 if increased):\n", new_size);
    for (i = n; i < new_size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr_realloc[i]);
    }

    // Print realloc array
    printf("Elements in realloc array:\n");
    for (i = 0; i < new_size; i++) {
        printf("%d ", arr_realloc[i]);
    }
    printf("\n");

    // Free all dynamically allocated memory
    free(arr_malloc);
    free(arr_calloc);
    free(arr_realloc);

    printf("Memory has been freed.\n");

    return 0;
}
