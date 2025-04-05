// [x] Length of linked list.
// [x] Find 3rd node from end.
// [x] Swap 2 adjacent nodes.
// [x] Implement Bubble Sort.
// [x] Assume there are 2 sorted lists, create a third list
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

struct Node *nthNodeFromEnd(struct Node *head, int pos);
void SwapNodes(struct Node *p, struct Node *q);
void BubbleSort(struct Node **head);
void Merge(struct Node *a, struct Node *b, struct Node **c);

int main() {
    struct Node *head = NULL;

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

    printf("3rd Node from the end is %d\n", nthNodeFromEnd(head, 3)->data);

    printf("Unsorted Linked List\n");
    Display(head);

    printf("Sorting...\n");
    BubbleSort(&head);

    printf("Sorted Linked List\n");
    Display(head);

    struct Node *A = NULL;
    struct Node *B = NULL;
    struct Node *C = NULL;

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

struct Node *nthNodeFromEnd(struct Node *head, int pos) {
    int s = Size(head);
    struct Node *p = head;
    for (int i = 0; i < s - pos; i++) {
        if (p == NULL)
            return NULL;
        p = p->next;
    }
    return p;
}

void SwapNodes(struct Node *p, struct Node *q) {
    int temp = p->data;
    p->data = q->data;
    q->data = temp;
}

void BubbleSort(struct Node **head) {
    if (*head == NULL)
        return;
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;
    do {
        swapped = 0;
        ptr1 = *head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                SwapNodes(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void Merge(struct Node *a, struct Node *b, struct Node **c) {
    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            Append(c, a->data);
            a = a->next;
        } else {
            Append(c, b->data);
            b = b->next;
        }
    }
    while (a != NULL) {
        Append(c, a->data);
        a = a->next;
    }
    while (b != NULL) {
        Append(c, b->data);
        b = b->next;
    }
}
