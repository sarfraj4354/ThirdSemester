#include <stdio.h>
#include <stdlib.h>

int number[50];

// Binary Search Function
int binarySearch(int A[], int l, int r, int key) {
    if (l <= r) {
        int mid = (l + r) / 2;
        if (A[mid] == key)
            return mid;
        else if (A[mid] < key)
            return binarySearch(A, mid + 1, r, key);
        else
            return binarySearch(A, l, mid - 1, key);
    }
    return -1;
}

int main() {
    printf("\tCompiled by Sarfraj Alam\n");
    printf("\t******BINARY SEARCH ALGORITHM******\n\n");

    int total;
    printf("Enter the total number of elements (max 50): ");
    scanf("%d", &total);

    if (total > 50 || total <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("\nEnter %d elements in ascending order:\n", total);
    for (int i = 0; i < total; i++) {
        scanf("%d", &number[i]);
    }

    char choice;
    do {
        int temp;
        printf("\nEnter the number to search in the array: ");
        scanf("%d", &temp);

        int index = binarySearch(number, 0, total - 1, temp);
        if (index != -1)
            printf("Element found at index %d.\n", index);
        else
            printf("Element not found in the array.\n");

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &choice);  // space before %c to consume newline

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
