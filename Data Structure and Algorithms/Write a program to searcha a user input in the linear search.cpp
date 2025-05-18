#include <stdio.h>

// Linear search function
int search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;  // return index of the found element
    }
    return -1;  // return -1 if not found
}

int main() {
    printf("\tCompiled by Sarfraj Alam\n");
    printf("\t******LINEAR SEARCH ALGORITHM******\n\n");

    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    char choice;

    do {
        printf("Enter element to search: ");
        scanf("%d", &x);

        int result = search(arr, n, x);
        if (result == -1)
            printf("Element is not present in the array.\n");
        else
            printf("Element is present at index (starting from 0): %d\n", result);

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &choice);  // space before %c to catch newline character

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
