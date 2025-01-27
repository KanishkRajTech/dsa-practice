// Insertion Sort Algorithm
// Write a C program to implement the Insertion Sort algorithm. The program should take an array of integers as input and sort them in ascending order using the Insertion Sort technique.


#include <stdio.h>
void insertionSort(int a[], int n) {
    int temp, j;
    
    for (int i = 1; i < n; i++) {
        temp = a[i]; 
        j = i - 1;

        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        
        a[j + 1] = temp;
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    insertionSort(a, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}
