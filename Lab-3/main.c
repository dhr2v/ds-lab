// [x] 1. Write a program to create a linked list.
// [x] 2. Traverse the linked list and print content of every struct Node.
// [x] 3. Create 2 linked lists having size 'n' & 'm' and add m respectively; derive 3rd list by concatenating these 2 lists.
// [x] 4. Insert a struct Node in the list at beginning, at end, at specific location.
// [x?] 5. Delete a struct Node in the list at beginning, at end, at specific location.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

/* FUNCTION DECLARATION */

int Size(struct Node *p);
void Display(struct Node *p);
// void Concat(struct Node *a, struct Node *b);
struct Node *Concat(struct Node *a, struct Node *b);
void Prepend(struct Node **head, int num);
void Append(struct Node **head, int num);
void Insert(struct Node **head, int num, int pos);
void Delete(struct Node **head, int num);
void DeleteAtPos(struct Node **head, int pos);

int main() {
    struct Node *head = NULL;

    printf("Creating Linked List...\n");
    for (int i = 1; i <= 10; i++)
        Insert(&head, i * 10, i);

    Display(head);

    printf("\n\n");

    Delete(&head, 40);
    Delete(&head, 90);
    Delete(&head, 20);
    Display(head);

    printf("\n\n");

    struct Node *x = NULL;
    for (int i = 1; i <= 4; i++)
        Insert(&x, i * 4, i);
    Display(x);
    printf("\n");

    struct Node *y = NULL;
    for (int i = 1; i <= 3; i++)
        Insert(&y, i * 7, i);
    Display(y);
    printf("\n");

    Display(Concat(x, y));

    return 0;
}

int Size(struct Node *p) {
    int size = 0;
    while (p != NULL) {
        p = p->next;
        size++;
    }
    return size;
}

void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

struct Node *Concat(struct Node *a, struct Node *b) {
    struct Node *c = NULL;

    while (a != NULL) {
        Append(&c, a->data);
        a = a->next;
    }

    while (b != NULL) {
        Append(&c, b->data);
        b = b->next;
    }

    return c;
}

void Prepend(struct Node **head, int num) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = num;
    temp->next = *head;
    *head = temp;
}

void Append(struct Node **head, int num) {
    struct Node *p = (*head);

    if (p == NULL) {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = num;
        p->next = NULL;
        (*head) = p;
        return;
    }

    while (p->next != NULL)
        p = p->next;

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = num;
    temp->next = NULL;
    p->next = temp;
}

void Insert(struct Node **head, int num, int pos) {
    if (pos > Size(*head) + 1 || pos < 1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        Prepend(head, num);
        return;
    }

    pos -= 2;

    struct Node *p = (*head);
    while (pos--)
        p = p->next;

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = num;
    temp->next = p->next;
    p->next = temp;
}

void Delete(struct Node **head, int num) {
    struct Node *p = (*head);

    while (p->next != NULL) {
        if (p->next->data == num) {
            struct Node *q = p->next;
            p->next = p->next->next;
            return;
        }
        p = p->next;
    }

    printf("Given list does not have %d\n", num);
}
