// Quick Sort Algorithm
// Write a C program to implement the Quick Sort algorithm. The program should take an array of integers as input and sort them in ascending order using the Quick Sort technique with the first element as the pivot.

#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int A[], int lb, int ub) {
    int pivot = A[lb];
    int start = lb;
    int end = ub;

    while (start < end) {
        while (A[start] <= pivot && start < ub)
            start++;
        while (A[end] > pivot)
            end--;

        if (start < end)
            swap(&A[start], &A[end]);
    }

    swap(&A[lb], &A[end]);
    return end;
}

void QuickSort(int A[], int lb, int ub) {
    if (lb < ub) {
        int loc = Partition(A, lb, ub);
        QuickSort(A, lb, loc - 1);
        QuickSort(A, loc + 1, ub);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    QuickSort(A, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    
    printf("\n");
    return 0;
}
