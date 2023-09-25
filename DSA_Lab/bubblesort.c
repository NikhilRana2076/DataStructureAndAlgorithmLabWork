#include <stdio.h> 
void swap(int *a, int *b) { 
int temp = *a; 
*a = *b; 
*b = temp; 
} 
void bubbleSort(int arr[], int n) { 
int i, j; 
int swapped; // A flag to optimize the sorting process 
for (i = 0; i < n - 1; i++) { //if i=0; it completes 1st pass....i=1;it completes 2nd pass..... swapped = 0; // Initialize the flag to 0 
for (j = 0; j < n - i - 1; j++) { 
if (arr[j] > arr[j + 1]) { 
swap(&arr[j], &arr[j + 1]); 
swapped = 1; // Set the flag to 1 if any swap occurs 
} 
} 
// If no swap occurs in the inner loop, the array is already sorted 
// and we can break out of the outer loop early 
if (swapped == 0) { 
break; 
} 
} 
} 
int main() { 
int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
int n = sizeof(arr) / sizeof(arr[0]); 
printf("Unsorted array: "); 
for (int i = 0; i < n; i++) { 
printf("%d ", arr[i]); 
} 
bubbleSort(arr, n); 
printf("\nSorted array: "); 
for (int i = 0; i < n; i++) {
printf("%d ", arr[i]); 
} 
printf("\n"); 
return 0; 
} 

