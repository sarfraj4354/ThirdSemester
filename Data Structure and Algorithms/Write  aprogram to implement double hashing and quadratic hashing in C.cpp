#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define DOUBLE_HASHING 1
#define QUADRATIC_PROBING 2

int hash_table[TABLE_SIZE] = {0};

// Hash functions
int hash1(int key) {
    return key % TABLE_SIZE;
}

int hash2(int key) {
    return 7 - (key % 7);
}

// Insertion function
void insert(int method) {
    int key, index, i;
    printf("\nEnter a value to insert into the hash table: ");
    scanf("%d", &key);

    index = hash1(key);
    if (hash_table[index] == 0) {
        hash_table[index] = key;
        return;
    }

    if (method == DOUBLE_HASHING) {
        int increment = hash2(key);
        for (i = 1; i < TABLE_SIZE; i++) {
            index = (hash1(key) + i * increment) % TABLE_SIZE;
            if (hash_table[index] == 0) {
                hash_table[index] = key;
                return;
            }
        }
    } else if (method == QUADRATIC_PROBING) {
        for (i = 1; i < TABLE_SIZE; i++) {
            index = (hash1(key) + i * i) % TABLE_SIZE;
            if (hash_table[index] == 0) {
                hash_table[index] = key;
                return;
            }
        }
    }

    printf("\nElement cannot be inserted. Table might be full.\n");
}

// Search function
void search(int method) {
    int key, index, i;
    printf("\nEnter element to search: ");
    scanf("%d", &key);

    index = hash1(key);
    if (hash_table[index] == key) {
        printf("Value is found at index %d\n", index);
        return;
    }

    if (method == DOUBLE_HASHING) {
        int increment = hash2(key);
        for (i = 1; i < TABLE_SIZE; i++) {
            index = (hash1(key) + i * increment) % TABLE_SIZE;
            if (hash_table[index] == key) {
                printf("Value is found at index %d\n", index);
                return;
            }
        }
    } else if (method == QUADRATIC_PROBING) {
        for (i = 1; i < TABLE_SIZE; i++) {
            index = (hash1(key) + i * i) % TABLE_SIZE;
            if (hash_table[index] == key) {
                printf("Value is found at index %d\n", index);
                return;
            }
        }
    }

    printf("Value is not found in the hash table.\n");
}

// Display function
void display() {
    printf("\n   Hash Table\n");
    printf("--------------------\n");
    printf("|  Index |  Value  |\n");
    printf("--------------------\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("|   %2d   |   %3d   |\n", i, hash_table[i]);
    }
    printf("--------------------\n");
}

int main() {
    printf("\tCompiled by Sarfraj Alam\n");
    int choice, method = DOUBLE_HASHING;

    while (1) {
        printf("\nChoose Hashing Method:\n");
        printf("1. Double Hashing\n");
        printf("2. Quadratic Probing\n");
        printf("3. Continue with current method\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        int modeChoice;
        scanf("%d", &modeChoice);

        if (modeChoice == 1) {
            method = DOUBLE_HASHING;
        } else if (modeChoice == 2) {
            method = QUADRATIC_PROBING;
        } else if (modeChoice == 4) {
            exit(0);
        }

        printf("\n--- Operations Menu ---\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(method);
                break;
            case 2:
                display();
                break;
            case 3:
                search(method);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again!\n");
        }
    }

    return 0;
}
