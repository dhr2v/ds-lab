// [x] Length of linked list.
// [ ] Find 3rd node from end.
// [ ] Swap 2 adjacent nodes.
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
void Prepend(struct Node **head, int num);
void Display(struct Node *head);

struct Node* nthNodeFromEnd(struct Node* head, int pos);

int main () {
    struct Node *head = NULL;

    Prepend(&head, 35);
    Prepend(&head, 1);
    Prepend(&head, 50);
    Prepend(&head, 5);
    Prepend(&head, 30);
    Prepend(&head, 20);
    Prepend(&head, 10);

    Display(head);

    printf("Size of Linked List = %d\n", Size(head));

    printf("\n3rd Node from the end is %d", nthNodeFromEnd(head, 3)->data);

    return 0;
}

void Prepend(struct Node **head, int num) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = num;
    temp->next = *head;
    *head = temp;
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
