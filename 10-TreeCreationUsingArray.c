#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insertLevelOrder(int arr[], int i, int n) {
    struct Node* root = NULL;
    if (i < n) {
        root = newNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    int arr[100];
    int n, i;

    printf("Eleman sayisini girin: ");
    scanf("%d", &n);

    printf("Elemanlari girin: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = insertLevelOrder(arr, 0, n);

    printf("Agac Olusturuldu (Inorder): ");
    inOrder(root);
    printf("\n");

    return 0;
}