#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;
}

void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL)
        return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}

void printList(struct Node* node) {
    struct Node* last;
    printf("\nDuz Dolasma: ");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nTers Dolasma: ");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 40);

    printf("Liste olusturuldu:");
    printList(head);

    insertAfter(head->next, 30);
    printf("20 ile 40 arasina 30 eklendi:");
    printList(head);

    deleteNode(&head, head->next);
    printf("Ikinci eleman silindi:");
    printList(head);

    return 0;
}