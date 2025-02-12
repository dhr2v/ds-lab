#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* reverseLinkedList(struct Node *head);

void display(struct Node *head);

int main() {
    struct Node* H = NULL;
    struct Node* temp = NULL;
    struct Node* newNode = NULL;

    newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = 1;
    newNode->next = H;
    H = newNode;

    newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = 2;
    newNode->next = H;
    H = newNode;

    newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = 3;
    newNode->next = H;
    H = newNode;

    printf("Original List: ");
    display(H);

    H = reverseLinkedList(H);

    printf("Reversed List: ");
    display(H);

    return 0;
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d\t", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* reverseLinkedList(struct Node *head) {
   struct Node* temp = head;  
   struct Node* prev = NULL;  

   while (temp != NULL) {  
       struct Node* front = temp->next;  
       temp->next = prev;  
       prev = temp;  
       temp = front; 
   }

   return prev;  
}
