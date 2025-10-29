#include <stdio.h>

#define SIZE 100

int tree[SIZE];

void initTree() {
    for (int i = 0; i < SIZE; i++) {
        tree[i] = -1;
    }
}

void insert(int value, int index) {
    if(index >= SIZE) {
        printf("Be in your limits\n");
        return;    
    }

    if (tree[index] != -1){
        printf("Stop trying she's got a boyfriend already🚬");
        return;
    }

    tree[index] = value;
}

void delete(int index) {
    if(index >= SIZE) {
        printf("tring tring: The person you're trying to delete is out of reach. Pls try someone in your limits");
    }

    if(tree[index] = -1) {
        printf("JISKA KOI NHI HOTA USKA BHGWAAN HOTA H... KUCHH NHI KR SKTE AAP YAHAN");
        return;
    }

    tree[index] = -1;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if(tree[i] != -1) {
            printf("Index %d: %d\n", i, tree[i]);
        }
    }
}

void inorderTraversal(int index) {
    if(index >= SIZE || tree[index] == -1) 
        return;

    inorderTraversal(2 * index + 1);
    printf("%d ", tree[index]);
    inorderTraversal(2 * index + 2);
}


void preorderTraversal(int index) {
    if(index >= SIZE || tree[index] == -1) 
        return;

    printf("%d ", tree[index]);    
    preorderTraversal(2 * index + 1);
    preorderTraversal(2 * index + 2);
}

void postorderTraversal(int index) {
    if (index >= SIZE || tree[index] == -1) return;

    postorderTraversal(2 * index + 1);
    postorderTraversal(2 * index + 2);
    printf("%d ", tree[index]);
}

