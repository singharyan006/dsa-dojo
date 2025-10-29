#include <stdio.h>

#define SIZE 100

int tree[SIZE];

// Initialise the tree with -1 
void initTree() {
    for(int i = 0; i < SIZE; i++) 
        tree[i] = -1;
}

void insert(int value, int index) {
    if (index >= SIZE) { 
        printf("Index out of bounds\n");
        return;
    }
    if (tree[index] != -1) {
        printf("Already occupied at index %d\n", index);
        return;
    }
    tree[index] = value;
}

void delete(int index) {
    if (index >= SIZE) {
        printf("Index out of bounds\n");
        return;
    }
    if (tree[index] == -1) {
        printf("No node to delete at index %d\n", index);
        return;
    }
    tree[index] = -1;
}

int search(int value) {
    for (int i = 0; i < SIZE; i++) {
        if (tree[i] == value) {
            return i; // Return first index found
        }
    }
    return -1; // Not found
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (tree[i] != -1) {
            printf("Index %d: %d\n", i, tree[i]);
        }
    }
}

// Inorder traversal (left, root, right)
void inorderTraversal(int index) {
    if (index >= SIZE || tree[index] == -1) return;

    inorderTraversal(2 * index + 1); // Left child
    printf("%d ", tree[index]);
    inorderTraversal(2 * index + 2); // Right child
}

// Preorder traversal (root, left, right)
void preorderTraversal(int index) {
    if (index >= SIZE || tree[index] == -1) return;

    printf("%d ", tree[index]);
    preorderTraversal(2 * index + 1);
    preorderTraversal(2 * index + 2);
}

// Postorder traversal (left, right, root)
void postorderTraversal(int index) {
    if (index >= SIZE || tree[index] == -1) return;

    postorderTraversal(2 * index + 1);
    postorderTraversal(2 * index + 2);
    printf("%d ", tree[index]);
}

// Count the number of nodes in the tree
int countNodes() {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (tree[i] != -1) count++;
    }
    return count;
}

int main() {
    initTree();
    insert(10, 0); // root
    insert(20, 1);
    insert(30, 2);
    insert(40, 3);
    insert(50, 4);
    insert(60, 5);
    insert(70, 6);

    printf("Tree nodes:\n");
    display();

    printf("\nInorder Traversal: ");
    inorderTraversal(0);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(0);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(0);
    printf("\n");

    int val = 50;
    int foundIndex = search(val);
    if (foundIndex != -1) {
        printf("\nValue %d found at index %d\n", val, foundIndex);
    } else {
        printf("\nValue %d not found\n", val);
    }

    printf("\nDeleting value at index 4\n");
    delete(4);

    printf("After deletion, tree nodes:\n");
    display();

    printf("\nTotal nodes in tree: %d\n", countNodes());

    return 0;
}
