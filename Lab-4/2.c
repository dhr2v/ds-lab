// [x] Length of linked list.
// [x] Find 3rd node from end.
// [x] Swap 2 adjacent nodes.
// [ ] Implement Bubble Sort.
// [ ] Assume there are 2 sorted lists, create a third list 
//            from those two such that it is sorted as well.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int Size(struct Node *head);
void Append(struct Node **head, int num);
void Prepend(struct Node **head, int num);
void Display(struct Node *head);

struct Node* nthNodeFromEnd(struct Node* head, int pos);
void SwapNodes(struct Node *p, struct Node *q);
void BubbleSort(struct Node** head);
void Merge(struct Node* a, struct Node* b, struct Node** c);

int main () {
    struct Node *head = NULL;

    // Prepend(&head, 35);
    // Prepend(&head, 1);
    // Prepend(&head, 50);
    // Prepend(&head, 5);
    // Prepend(&head, 30);
    // Prepend(&head, 20);
    // Prepend(&head, 10);
    Append(&head, 10);
    Append(&head, 20);
    Append(&head, 30);
    Append(&head, 5);
    Append(&head, 50);
    Append(&head, 1);
    Append(&head, 35);

    Display(head);

    printf("Size of Linked List = %d\n", Size(head));
    printf("\nAfter swapping 1st & 2nd Node\n");
    SwapNodes(head, head->next);
    Display(head);
    // printf("\n3rd Node from the end is %d", nthNodeFromEnd(head, 3)->data);

    printf("Unsorted Linked List\n");
    Display(head);

    printf("Sorting...\n");
    BubbleSort(&head);

    printf("Sorted Linked List\n");
    Display(head);

    struct Node* A = NULL;
    struct Node* B = NULL;
    struct Node* C = NULL;

    Append(&A, 10);
    Append(&A, 20);
    Append(&A, 30);
    Append(&A, 40);

    Append(&B, 5);
    Append(&B, 8);
    Append(&B, 25);
    Append(&B, 35);

    printf("\nList 1:\n");
    Display(A);
    printf("\nList 2:\n");
    Display(B);

    Merge(A, B, &C);
    
    printf("\nList 3:\n");
    Display(C);

    return 0;
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
        Prepend(head, num);
        return;
    }

    while (p->next != NULL)
        p = p->next;

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = num;
    temp->next = NULL;
    p->next = temp;
}

void Display(struct Node *head) {
    struct Node *p = head;
    while (p != NULL) {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

int Size(struct Node *head) {
    int c = 0;
    struct Node *p = head;
    while (p != NULL) {
        c++;
        p = p->next;
    }
    return c;
}

struct Node* nthNodeFromEnd(struct Node* head, int pos) {
    int c = 0;
    int s = Size(head);

    struct Node* p = head;
    while (c < (s - pos) && p != NULL) {
        p = p->next;
        c++;
    }
    return p;
}

void SwapNodes(struct Node *p, struct Node *q) {
    int temp = p->data;
    p->data = q->data;
    q->data = temp;
}

void Merge(struct Node* a, struct Node* b, struct Node** c) {
    struct Node* p = a;
    struct Node* q = b;
    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            Append(c, p->data);
            p = p->next;
        } else {
            Append(c, q->data);
            q = q->next;
        }
    }
}   
