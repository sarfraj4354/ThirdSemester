#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left, *right;
} s_node;

// Create a new node
s_node *newNode(int item) {
    s_node *temp = (s_node *)malloc(sizeof(s_node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Inorder Traversal
void inorder(s_node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d -> ", root->key);
        inorder(root->right);
    }
}

// Insert a node
s_node *insert(s_node *node, int key) {
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

// Find the node with minimum key (inorder successor)
s_node *minValueNode(s_node *node) {
    s_node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete a node
s_node *deleteNode(s_node *root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with one or no child
        if (root->left == NULL) {
            s_node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            s_node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get inorder successor
        s_node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Search a node
s_node *search(s_node *root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}

// Free all nodes of the tree
void freeTree(s_node *root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function
int main() {
    printf("\tCompiled by Sarfraj Alam\n");

    s_node *root = NULL;
    s_node *srh;
    int choice, key;

    while (1) {
        printf("\nEnter your choice\n1. Insertion\n2. Deletion\n3. Traversal (Inorder)\n4. Search\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to be inserted: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;

            case 2:
                printf("Enter the key to be deleted: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("NULL\n");
                break;

            case 4:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                srh = search(root, key);
                printf(srh ? "Key found\n" : "Key not found\n");
                break;

            case 5:
                freeTree(root);
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Wrong choice!! Try again...\n");
        }
    }

    return 0;
}
