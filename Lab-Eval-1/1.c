// Dhruv Anand [BT24CSH023]
// Lab Evaluation (12th Feb 2025)

// Question 1: Quick Sort & Merge Sort

#include <stdio.h>

void display(int *arr, int size);
void swap(int *a, int *b);

int Partition(int *arr, int lb, int ub);
void QuickSort(int *arr, int lb, int ub);

void Merge(int *arr, int l, int m, int r);
void MergeSort(int *arr, int l, int r);

int main() {
    int A[] = {8, 5, 7, 3, 2};
    int n = sizeof(A) / sizeof(A[0]);

    int B[] = {8, 5, 7, 3, 2};
    int m = sizeof(B) / sizeof(B[0]);

    printf("Sorting array using Quick Sort\n");
    display(A, n);

    QuickSort(A, 0, n - 1);
    display(A, n);

    printf("\n");

    printf("Sorting array using Merge Sort\n");
    display(B, m);

    MergeSort(B, 0, n - 1);
    display(B, m);

    return 0;
}

void display(int *arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int *arr, int lb, int ub) {
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while (start < end) {
        while (arr[start] <= pivot && start < ub)
            start++;
        while (arr[end] > pivot && end > lb)
            end--;
        if (start < end)
            swap(&arr[start], &arr[end]);
    }
    swap(&arr[end], &arr[lb]);
    return end;
}

void QuickSort(int *arr, int lb, int ub) {
    if (lb < ub) {
        int pos = Partition(arr, lb, ub);
        QuickSort(arr, lb, pos - 1);
        QuickSort(arr, pos + 1, ub);
    }
}

void Merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void MergeSort(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        Merge(arr, l, m, r);
    }
}
