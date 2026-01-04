#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void traversal(struct Node *head) {
    struct Node *temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

void insertEnd(struct Node **head, int data) {
    struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = *head;
    ptr1->data = data;
    ptr1->next = *head;

    if (*head != NULL) {
        while (temp->next != *head)
            temp = temp->next;
        temp->next = ptr1;
    } else
        ptr1->next = ptr1;

    *head = ptr1;
}

void insertAfter(struct Node *head, int item, int data) {
    struct Node *temp = head;
    struct Node *newNode;
    if (head == NULL) return;

    do {
        if (temp->data == item) {
            newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

void deleteNode(struct Node **head, int key) {
    if (*head == NULL) return;

    struct Node *curr = *head, *prev;
    
    if (curr->data == key && curr->next == *head) {
        *head = NULL;
        free(curr);
        return;
    }

    if (curr->data == key) {
        prev = *head;
        while (prev->next != *head)
            prev = prev->next;
        prev->next = curr->next;
        *head = curr->next;
        free(curr);
    } 
    else {
        while (curr->data != key) {
            if (curr->next == *head) return;
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        free(curr);
    }
}

int main() {
    struct Node *head = NULL;
    
    struct Node *node1 = (struct Node*)malloc(sizeof(struct Node));
    node1->data = 10;
    head = node1;
    node1->next = head;

    struct Node *node2 = (struct Node*)malloc(sizeof(struct Node));
    node2->data = 20;
    node1->next = node2;
    node2->next = head;

    struct Node *node3 = (struct Node*)malloc(sizeof(struct Node));
    node3->data = 40;
    node2->next = node3;
    node3->next = head;

    printf("Liste: ");
    traversal(head);

    insertAfter(head, 20, 30);
    printf("Eklendi: ");
    traversal(head);

    deleteNode(&head, 10);
    printf("Silindi: ");
    traversal(head);

    return 0;
}