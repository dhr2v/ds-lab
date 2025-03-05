// 1. Create a doubly linked list and print the doubly linked list.
// 	 i. In forward direction
// 	ii. In reverse direction
// 2. Insert a node in doubly linked list
// 	  i. At beginning 
// 	 ii. At end
// 	iii. At specific position
// 3. Delete a node from doubly linked list
// 	  i. At beginning 
// 	 ii. At end
// 	iii. At specific position

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function declarations
void Display(struct Node *head);
int Size(struct Node *head);

void Prepend(struct Node **head, int num);
void Append(struct Node **head, int num);
void Insert(struct Node **head, int num, int pos);

void DeleteAtBeg(struct Node **head);
void DeleteAtEnd(struct Node **head);
void DeleteAtPos(struct Node **head, int pos);

int main() {
    struct Node* head = NULL;
    
    // Create dummy doubly linked list.
    for (int i = 1; i <= 10; i++) {
        Insert(&head, i * 2, i);
    }
    Display(head);

    DeleteAtEnd(&head);

    Display(head);

    DeleteAtBeg(&head);

    Display(head);

    return 0;
}

void Display(struct Node* head) {
    struct Node* p = head;
    while (p != NULL) {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

int Size(struct Node *head) {
    struct Node *p = head;
    int size = 0;
    while (p != NULL) {
       size++;
       p = p->next;
    } 
    return size;
}

void Prepend(struct Node **head, int num) {
    struct Node* p = (struct Node *)malloc(sizeof(struct Node));
    p->data = num;
    if (*head == NULL) {
        p->next = NULL;
        p->prev = NULL;
        *head = p;
        return;
    }
    p->next = *head;
    (*head)->prev = p;
    p->prev = NULL;
    *head = p;
}

void Append(struct Node **head, int num) { 
    struct Node* p = (struct Node *)malloc(sizeof(struct Node));
    p->data = num;

    if (*head == NULL) {
        p->prev = NULL;
        p->next = NULL;
        *head = p;
        return;
    }

    struct Node* tail = *head;

    while (tail->next != NULL) tail = tail->next;

    tail->next = p;
    p->prev = tail;
    p->next = NULL;

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

    if (temp->next != NULL) {
        temp->next->prev = p;
    }

    temp->next = p;
}
void DeleteAtBeg (struct Node **head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void DeleteAtEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(temp);
}

void DeleteAtPos(struct Node **head, int pos) {
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

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}
