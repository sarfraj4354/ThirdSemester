#include <stdio.h>

// Bubble Sort Function
void bubbleSort(int A[], int n, int choice) {
    for (int i = 0; i < n - 1; i++) {
        printf("Pass %d:\n", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d\t", A[k]); // Show array before sorting this pass
        }
        printf("\n");

        // Bubble sort logic
        for (int j = 0; j < n - i - 1; j++) {
            if ((choice == 1 && A[j] > A[j + 1]) || (choice == 2 && A[j] < A[j + 1])) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }

            // Show intermediate array after each comparison and possible swap
            for (int k = 0; k < n; k++) {
                printf("%d\t", A[k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    printf("\nThe sorted data is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

int main() {
    printf("\t*****Compiled by Jonash Chataut*****\n");
    printf("\t****BUBBLE SORT ALGORITHM****\n\n");

    int terms;
    printf("Enter the number of terms to be sorted: ");
    scanf("%d", &terms);

    int numbers[terms];
    printf("Enter the numbers to be sorted:\n");
    for (int i = 0; i < terms; i++) {
        scanf("%d", &numbers[i]);
    }

    int choice;
    printf("\nChoose sorting order:");
    printf("\n1. Ascending");
    printf("\n2. Descending\n");
    scanf("%d", &choice);

    if (choice == 1 || choice == 2)
        bubbleSort(numbers, terms, choice);
    else
        printf("\nInvalid option selected.\n");

    return 0;
}
