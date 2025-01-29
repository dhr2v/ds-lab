# Linked List Implementation in C

This repository contains C source code for implementing a linked list. The code includes functions to create a list, insert nodes at specific positions, append nodes, prepend nodes, display the list, and delete nodes by finding their value in the list.

## Files

- [`main.c`](https://github.com/dhr2v/ds-lab/blob/main/Lab-3/main.c)

  - Contains the implementation of the linked list and its associated functions.

## Functions

### `int Size(struct Node *p)`

Calculates the size of the linked list.

**Parameters:**

- `struct Node *p`: Pointer to the head of the list.

**Returns:**

- The size of the list as an integer.

### `void Display(struct Node *p)`

Displays the contents of the linked list.

**Parameters:**

- `struct Node *p`: Pointer to the head of the list.

**Usage:**

```c
Display(head);
```

### `struct Node *Concat(struct Node *a, struct Node *b)`

Concatenates two linked lists and returns the head of the new list.

**Parameters:**

- `struct Node *a`: Pointer to the head of the first list.
- `struct Node *b`: Pointer to the head of the second list.

**Returns:**

- Pointer to the head of the concatenated list.

**Usage:**

```c
struct Node *newList = Concat(list1, list2);
```

### `void Prepend(struct Node **head, int num)`

Inserts a node at the beginning of the list.

**Parameters:**

- `struct Node **head`: Double pointer to the head of the list.
- `int num`: Data to be inserted.

**Usage:**

```c
Prepend(&head, 10);
```

### `void Append(struct Node **head, int num)`

Appends a node at the end of the list.

**Parameters:**

- `struct Node **head`: Double pointer to the head of the list.
- `int num`: Data to be inserted.

**Usage:**

```c
Append(&head, 20);
```

### `void Insert(struct Node **head, int num, int pos)`

Inserts a node at a specific position in the list.

**Parameters:**

- `struct Node **head`: Double pointer to the head of the list.
- `int num`: Data to be inserted.
- `int pos`: Position at which the node should be inserted.

**Usage:**

```c
Insert(&head, 30, 3);
```

### `void Delete(struct Node **head, int num)`

Deletes a node by finding its value in the list.

**Parameters:**

- `struct Node **head`: Double pointer to the head of the list.
- `int num`: Data value of the node to be deleted.

**Usage:**

```c
Delete(&head, 40);
```

## How to Use

1. **Creating a Linked List:**

   - Use the `Insert`, `Append`, or `Prepend` functions to create and populate the list.

2. **Displaying the List:**

   - Use the `Display` function to print the contents of the list.

3. **Concatenating Lists:**

   - Use the `Concat` function to concatenate two lists.

4. **Deleting a Node:**
   - Use the `Delete` function to remove a node by its value.

## Example

```c
int main() {
    struct Node *head = NULL;

    // Creating Linked List
    for (int i = 1; i <= 10; i++)
        Insert(&head, i * 10, i);

    // Displaying the List
    Display(head);
    printf("\n");

    // Deleting Nodes
    Delete(&head, 40);
    Delete(&head, 90);
    Delete(&head, 20);
    Display(head);
    printf("\n");

    // Concatenating Lists
    struct Node *x = NULL;
    for (int i = 1; i <= 4; i++)
        Insert(&x, i * 4, i);
    struct Node *y = NULL;
    for (int i = 1; i <= 3; i++)
        Insert(&y, i * 7, i);
    struct Node *z = Concat(x, y);
    Display(z);

    return 0;
}
```

This example demonstrates how to create a linked list, display it, delete nodes, and concatenate two lists.
