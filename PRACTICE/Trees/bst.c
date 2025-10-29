#include <stdio.h>
#include <stdlib.h>

#define MAX 3   // Maximum number of keys in a node
#define MIN 2   // Minimum degree (t)

struct BTreeNode {
    int keys[MAX + 1];
    int count;
    struct BTreeNode *child[MAX + 1];
};

struct BTreeNode *root = NULL;

// Function to create a new node
struct BTreeNode* createNode(int key, struct BTreeNode* child) {
    struct BTreeNode* newNode = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    newNode->keys[1] = key;
    newNode->count = 1;
    newNode->child[0] = root;
    newNode->child[1] = child;
    return newNode;
}

// Insert the key into a non-full node
void insertNode(int key, int pos, struct BTreeNode* node, struct BTreeNode* child) {
    int j = node->count;
    while (j > pos) {
        node->keys[j + 1] = node->keys[j];
        node->child[j + 1] = node->child[j];
        j--;
    }
    node->keys[j + 1] = key;
    node->child[j + 1] = child;
    node->count++;
}

// Split the node when full
void splitNode(int key, int *pKey, int pos, struct BTreeNode* node, struct BTreeNode* child, struct BTreeNode** newNode) {
    int median, i, j;

    if (pos > MIN)
        median = MIN + 1;
    else
        median = MIN;

    *newNode = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    j = median + 1;
    while (j <= MAX) {
        (*newNode)->keys[j - median] = node->keys[j];
        (*newNode)->child[j - median] = node->child[j];
        j++;
    }
    (*newNode)->count = MAX - median;
    node->count = median;

    if (pos <= MIN)
        insertNode(key, pos, node, child);
    else
        insertNode(key, pos - median, *newNode, child);

    *pKey = node->keys[node->count];
    (*newNode)->child[0] = node->child[node->count];
    node->count--;
}

// Set the value recursively
int setValue(int key, int *pKey, struct BTreeNode* node, struct BTreeNode** child) {
    int pos;

    if (!node) {
        *pKey = key;
        *child = NULL;
        return 1;
    }

    if (key < node->keys[1]) pos = 0;
    else {
        for (pos = node->count; (key < node->keys[pos] && pos > 1); pos--);
        if (key == node->keys[pos]) {
            printf("Duplicate keys not allowed!\n");
            return 0;
        }
    }

    if (setValue(key, pKey, node->child[pos], child)) {
        if (node->count < MAX)
            insertNode(*pKey, pos, node, *child);
        else {
            splitNode(*pKey, pKey, pos, node, *child, child);
            return 1;
        }
    }
    return 0;
}

// Insert a key into the B-Tree
void insert(int key) {
    int flag, i;
    struct BTreeNode *child;

    flag = setValue(key, &i, root, &child);
    if (flag)
        root = createNode(i, child);
}

// Traverse the B-Tree (In-order)
void traversal(struct BTreeNode* node) {
    int i;
    if (node) {
        for (i = 0; i < node->count; i++) {
            traversal(node->child[i]);
            printf("%d ", node->keys[i + 1]);
        }
        traversal(node->child[i]);
    }
}

int main() {
    int n, key, i;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &key);
        insert(key);
    }

    printf("\nB-Tree Traversal (In-Order): ");
    traversal(root);
    printf("\n");

    return 0;
}
