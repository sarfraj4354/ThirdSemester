#include <stdio.h>

void selectionSort(int A[], int n, int choice) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i; // Assume first element is min/max
        printf("Pass %d:\n", i + 1);

        // Print current state of array before sorting this pass
        for (int k = 0; k < n; k++) {
            printf("%d\t", A[k]);
        }
        printf("\n");

        // Find the min or max index based on choice
        for (int j = i + 1; j < n; j++) {
            if ((choice == 1 && A[j] < A[min_index]) || (choice == 2 && A[j] > A[min_index])) {
                min_index = j;
            }
        }

        // Swap if a new min/max was found
        if (min_index != i) {
            int temp = A[min_index];
            A[min_index] = A[i];
            A[i] = temp;
        }
    }

    // Print the final sorted array
    printf("\nThe sorted data is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

int main() {
    printf("\tCompiled by Sarfraj Alam\n");
    printf("\t*****SELECTION SORT******\n\n");

    int terms;
    printf("Enter the number of terms to be sorted: ");
    scanf("%d", &terms);

    int numbers[terms];
    printf("Enter the numbers to be sorted: \n");
    for (int i = 0; i < terms; i++) {
        scanf("%d", &numbers[i]);
    }

    int choice;
    printf("\nChoose sorting order:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");

    if (choice == 1 || choice == 2)
        selectionSort(numbers, terms, choice);
    else
        printf("Invalid option selected.\n");

    return 0;
}
