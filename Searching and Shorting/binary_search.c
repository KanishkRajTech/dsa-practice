// Binary Search Algorithm

// Write a C program to implement the Binary Search algorithm. 
// The program should accept a sorted array of integers and a target element,
// then determine whether the element is present in the array. If found, return the index; 
// otherwise, return -1.

#include <stdio.h>

int binarySearch(int a[], int n, int data) {
    int l = 0, r = n - 1;
    
    while (l <= r) {
        int mid = (l + r) / 2;
        
        if (a[mid] == data)
            return mid; 
        
        else if (data < a[mid])
            r = mid - 1;  
        
        else
            l = mid + 1; 
    }
    
    return -1; 
}

int main() {
    int n, data;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int a[n];
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    printf("Enter the element to search: ");
    scanf("%d", &data);
    
    int result = binarySearch(a, n, data);
    
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");
    
    return 0;
}
