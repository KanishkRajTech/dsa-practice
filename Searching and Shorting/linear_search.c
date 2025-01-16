// Implement Linear Search in an Array

// Write a C program that performs a linear search on an array. The program should:

// 1).Take input for the number of elements in the array (n).
// 2).Accept n integer values from the user.
// 3).Ask the user for the element (data) to search in the array.
// 4).Perform a linear search to find the index of the given element.
// 5).Print the index of the first occurrence of the element, if found.
// 6).If the element is not found, display an appropriate message.

#include <stdio.h>

void main() {
    int n, data, i;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int a[n];
    
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("Enter the element to search: ");
    scanf("%d", &data);
    
    for(i = 0; i < n; i++) {
        if(a[i] == data) {
            printf("Element found at index %d\n", i);
            break;
        }
    }
    
    if(i == n) {
        printf("Element not found\n");
    }
}
