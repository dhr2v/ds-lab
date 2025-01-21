//  ____  _                           _                          _ 
// |  _ \| |__  _ __ _   ___   __    / \   _ __   __ _ _ __   __| |
// | | | | '_ \| '__| | | \ \ / /   / _ \ | '_ \ / _` | '_ \ / _` |
// | |_| | | | | |  | |_| |\ V /   / ___ \| | | | (_| | | | | (_| |
// |____/|_| |_|_|   \__,_| \_/   /_/   \_\_| |_|\__,_|_| |_|\__,_|
//
// [x] create an integer array of size n and display it take value of the n from the user also the element of the array
// [x] insert an element into array at beginning, end and at specific position
// [ ] perform delete operation first, last and at specific position
// [ ] search an element in the array (linear search)
// [ ] sorting
// [ ] sort only array element only at index even
// [ ] sort only array element only at index odd
// [ ] sort the element which are even
// [ ] sort the element which are odd

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

void display_array(int* array, int size);
void insert_at_begin(int* array, int* size, int num);
void insert_at_end(int* array, int* size, int num);
void insert_at_pos(int* array, int* size, int num, int pos);

int main ()  {
    int n;
    printf("Enter the size for the array.\n");
    scanf("%d", &n);
    printf("Creating an array of size %d\n", n);

    int arr[MAX_SIZE];

    for (int i = 0; i < n; i++) {
        printf("Enter the number.\n");
        scanf("%d", &arr[i]);
    }

    printf("Displaying array elements\n");
    display_array(arr, n);

    printf("Inserting 24 at the beginning\n");
    insert_at_begin(arr, &n, 24);
    display_array(arr, n);

    printf("Inserting 12 at the end\n");
    insert_at_end(arr, &n, 12);
    display_array(arr, n);

    printf("Inserting 69 at the 4th position\n");
    insert_at_pos(arr, &n, 69, 4);
    display_array(arr, n);

    return 0;
}

void display_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        if ((i + 1) % 10 == 1 && (i + 1) % 100 != 11) {
            printf("%dst element : %d\n", (i + 1), array[i]);
        }
        else if ((i + 1) % 10 == 2 && (i + 1) % 100 != 12) {
            printf("%dnd element : %d\n", (i + 1), array[i]);
        }
        else if ((i + 1) % 10 == 3 && (i + 1) % 100 != 13) {
            printf("%drd element : %d\n", (i + 1), array[i]);
        } 
        else {
            printf("%dth element : %d\n", (i + 1), array[i]);
        }
    }
} 

void insert_at_begin(int* array, int* size, int num) {
   for (int i = *size - 1; i >= 0; i--) {
        array[i + 1] = array[i];
   } 
   array[0] = num;
   (*size)++;
}

void insert_at_end(int* array, int* size, int num) {
   array[*size] = num; 
   (*size)++;
}

void insert_at_pos(int* array, int* size, int num, int pos) {
   for (int i = *size - 1; i >= pos; i--) {
        array[i + 1] = array[i];
   }     
   array[pos - 1] = num;
   (*size)++;
}
