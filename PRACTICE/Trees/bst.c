#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert data into BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } // Ignore duplicate values
    return root;
}

// Inorder traversal (sorted order for BST)
void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Search for a value in BST
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

// Find minimum value node in subtree
Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node from BST
Node* delete(Node* root, int data) {
    if (root == NULL)
        return root;
    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        // Node found
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of BST: ");
    inorderTraversal(root);
    printf("\n");

    int key = 40;
    Node* found = search(root, key);
    if (found)
        printf("Found %d in BST.\n", key);
    else
        printf("%d not found in BST.\n", key);

    printf("Deleting %d from BST.\n", key);
    root = delete(root, key);

    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
