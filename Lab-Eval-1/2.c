#include <stdio.h>

void reverse_subarray(int *arr, int low, int high);

int main() {
    int A[] = {8, 5, 7, 3, 2, 9, 1, 6};
    int n = sizeof(A) / sizeof(A[0]);

    for (int i = 0; i < n; i++) printf("%d\t", A[i]);
    printf("\n");

    reverse_subarray(A, 2, 6);

    for (int i = 0; i < n; i++) printf("%d\t", A[i]);
    return 0;
}

void reverse_subarray(int *arr, int low, int high) {
    int i = low, j = high;
    
    while (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}
