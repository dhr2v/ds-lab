// 	1. Create and traverse Circular Linked List
//  2. Insert a node at specific location in a Circular Linked List
//  3. Delete a node from Circular Linked List
//
//  4. Suppose we have 2 circular linked list, form a new circular linked list by joining those 2 lists.
//  5. Assume that you have 2 sorted circular linked lists, merge them to form another sorted circular linked list.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function declarations
void Display(struct Node* head);
void Prepend(struct Node **head, int num);
void Append(struct Node **head, int num);
void Insert(struct Node **head, int num, int pos);
void DeleteAtBeginning(struct Node **head);
void DeleteAtEnd(struct Node **head);
void DeleteAtPosition(struct Node **head, int pos);

int main() {
    struct Node* head = NULL;

    // Create dummy circular doubly linked list.
    for (int i = 1; i <= 8; i *= 2) {
        Prepend(&head, i);
    }

    printf("Circular Doubly Linked List in Forward Direction:\n");
    Display(head);

    Append(&head, 16);
    Insert(&head, 32, 3);  

    printf("\nAfter Inserting 16 at the end and 32 at position 3:\n");
    Display(head);

    // Deleting nodes
    DeleteAtBeginning(&head);
    DeleteAtEnd(&head);
    DeleteAtPosition(&head, 2);

    printf("\nAfter Deleting at the beginning, end, and position 2:\n");
    Display(head);

    return 0;
}

void Display(struct Node* head) {
    if (head == NULL) return;
    struct Node* p = head;
    do {
        printf("%d\t", p->data);
        p = p->next;
    } while (p != head); // Loop until we reach the first node again
    printf("\n");
}

void Prepend(struct Node **head, int num) {
    struct Node* p = (struct Node *)malloc(sizeof(struct Node));
    p->data = num;

    if (*head == NULL) {
        p->next = p;
        p->prev = p;
        *head = p;
        return;
    }

    struct Node* last = (*head)->prev;
    p->next = *head;
    p->prev = last;
    last->next = p;
    (*head)->prev = p;
    *head = p;
}

void Append(struct Node **head, int num) {
    struct Node* p = (struct Node *)malloc(sizeof(struct Node));
    p->data = num;

    if (*head == NULL) {
        p->next = p;
        p->prev = p;
        *head = p;
        return;
    }

    struct Node* last = (*head)->prev;
    p->next = *head;
    p->prev = last;
    last->next = p;
    (*head)->prev = p;
}

void Insert(struct Node **head, int num, int pos) {
    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }

    struct Node* p = (struct Node *)malloc(sizeof(struct Node));
    p->data = num;

    if (pos == 1) {
        Prepend(head, num);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    p->next = temp->next;
    p->prev = temp;

    if (temp->next != *head) {
        temp->next->prev = p;
    } else {
        (*head)->prev = p; 
    }

    temp->next = p;
}

void DeleteAtBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }

    struct Node* temp = *head;
    if (*head == (*head)->next) { 
        free(temp);
        *head = NULL;
        return;
    }

    struct Node* last = (*head)->prev;
    *head = (*head)->next;
    (*head)->prev = last;
    last->next = *head;

    free(temp);
}

void DeleteAtEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }

    struct Node* last = (*head)->prev;
    if (*head == (*head)->next) {
        free(last);
        *head = NULL;
        return;
    }

    last->prev->next = *head;
    (*head)->prev = last->prev;

    free(last);
}

void DeleteAtPosition(struct Node **head, int pos) {
    if (*head == NULL || pos <= 0) {
        printf("Invalid position or empty list\n");
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    if (temp == *head) { 
        DeleteAtBeginning(head);
        return;
    }

    if (temp->next == *head) {
        DeleteAtEnd(head);
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}
