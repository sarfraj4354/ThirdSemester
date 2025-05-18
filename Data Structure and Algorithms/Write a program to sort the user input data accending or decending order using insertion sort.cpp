#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Display the array before insertion
        printf("Array before inserting %d: ", key);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");

        // Shift elements greater than key to the right
        while (j >= 0 && arr[j] > key) {
            printf("Shifting %d to the right\n", arr[j]);
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert the key at correct position
        arr[j + 1] = key;

        // Display the array after insertion
        printf("Array after inserting %d: ", key);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n\n");
    }
}

int main() {
    printf("\tCompiled by Sarfraj Alam\n");
    printf("\t******INSERTION SORT******\n\n");

    int arr_size;
    printf("Enter the size of the array: ");
    scanf("%d", &arr_size);

    int arr[arr_size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < arr_size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nGiven array is:\n");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Sort the array using insertion sort
    insertionSort(arr, arr_size);

    printf("Sorted array is:\n");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
