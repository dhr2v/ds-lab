// LL  : 10-20-30-5-50-1-35
// O/P : Smallest at first, largest at last.
// 	1-20-30-5-35-10-50
//
// 	10-5-20-7-9-30-15
// 	Split the LL at even & odd indices

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function prototypes
void Append(struct Node **head, int num);
void Display(struct Node *head);
void ArrangeFirstLast(struct Node **head);
void SplitEvenOdd(struct Node *head, struct Node **evenList, struct Node **oddList);
struct Node *GetSmallestNode(struct Node *head);
struct Node *GetLargestNode(struct Node *head);
void SwapNodes(struct Node *p, struct Node *q);

int main() {
    struct Node *head = NULL;
    struct Node *evenList = NULL;
    struct Node *oddList = NULL;

    // Creating the list 10-20-30-5-50-1-35
    Append(&head, 10);
    Append(&head, 20);
    Append(&head, 30);
    Append(&head, 5);
    Append(&head, 50);
    Append(&head, 1);
    Append(&head, 35);

    printf("Original Circular Linked List:\n");
    Display(head);

    ArrangeFirstLast(&head);
    printf("\nAfter arranging smallest at first & largest at last:\n");
    Display(head);

    // Splitting the list at even and odd indices
    SplitEvenOdd(head, &evenList, &oddList);
    printf("\nEven Index Linked List:\n");
    Display(evenList);
    printf("\nOdd Index Linked List:\n");
    Display(oddList);

    return 0;
}

void Append(struct Node **head, int num) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = num;
    if (*head == NULL) {
        temp->next = temp; // Circular link
        *head = temp;
        return;
    }
    struct Node *p = *head;
    while (p->next != *head)
        p = p->next;
    p->next = temp;
    temp->next = *head;
}

void Display(struct Node *head) {
    if (!head)
        return;
    struct Node *p = head;
    do {
        printf("%d\t", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}

void ArrangeFirstLast(struct Node **head) {
    struct Node *sm_Node = GetSmallestNode(*head);
    struct Node *lg_Node = GetLargestNode(*head);
    struct Node *st_Node = *head;
    struct Node *ed_Node = *head;
    while (ed_Node->next != *head)
        ed_Node = ed_Node->next;
    SwapNodes(sm_Node, st_Node);
    SwapNodes(lg_Node, ed_Node);
}

void SplitEvenOdd(struct Node *head, struct Node **evenList, struct Node **oddList) {
    if (!head)
        return;
    struct Node *p = head;
    int index = 1;
    do {
        if (index % 2 == 0)
            Append(evenList, p->data);
        else
            Append(oddList, p->data);
        p = p->next;
        index++;
    } while (p != head);
}

void SwapNodes(struct Node *p, struct Node *q) {
    int temp = p->data;
    p->data = q->data;
    q->data = temp;
}

struct Node *GetSmallestNode(struct Node *head) {
    struct Node *p = head;
    struct Node *out = p;
    int min_num = p->data;
    do {
        if (p->data < min_num) {
            min_num = p->data;
            out = p;
        }
        p = p->next;
    } while (p != head);
    return out;
}

struct Node *GetLargestNode(struct Node *head) {
    struct Node *p = head;
    struct Node *out = p;
    int max_num = p->data;
    do {
        if (p->data > max_num) {
            max_num = p->data;
            out = p;
        }
        p = p->next;
    } while (p != head);
    return out;
}
