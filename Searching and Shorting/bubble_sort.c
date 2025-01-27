Bubble Sort Algorithm
// Write a C program to implement the Bubble Sort algorithm. The program should take an array of integers as input and sort them in ascending order using the Bubble Sort technique. The algorithm should be optimized to stop early if no swaps occur in a pass.
#include <stdio.h>

void bubbleSort(int A[], int n) {
    int temp, flag;
    
    for (int i = 0; i < n - 1; i++) {
        flag = 0;
        
        for (int j = 0; j < n - i - 1; j++) {  
            if (A[j] > A[j + 1]) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                
                flag = 1;
            }
        }
        if (flag == 0)
            break;
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
    
    bubbleSort(A, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    
    printf("\n");
    
    return 0;
}
