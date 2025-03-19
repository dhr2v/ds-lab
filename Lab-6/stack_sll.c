// Implementation of stack using array.

#include <stdio.h>
#include <stdlib.h>

// Singly Linked List
struct Node {
    int data;
    struct Node* next;
};

/* FUNCTION DECLARATIONS */
void Push(int num);
void Pop();
void Display();

struct Node* top = NULL;

int main() {
    for (int i = 1; i <= 10; i++) Push(2 * i);

    Display();

    Pop();
    Pop();

    printf("Popped twice.\n");

    Display();

    return 0;
}

/* FUNCTION DEFINITIONS */
void Display() {
    struct Node* p = top;
    while (p != NULL) {
        printf("| %2d |\n", p->data);
        p = p->next;
    }
}

void Push (int num) {
    struct Node* p = (struct Node *)malloc(sizeof(struct Node));
    p->data = num;
    p->next = top;
    top = p;
}

void Pop() {
    struct Node* p = top;
    top = p->next;
    free(p);
}
