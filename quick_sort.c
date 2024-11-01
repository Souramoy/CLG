//c program for Quick Sort
#include <stdio.h>

void swap(int* a, int* b);

// Partition function
int partition(int arr[], int low, int high) {
    
    // Choose the pivot
    int pivot = arr[high];
    
    
    int i = low - 1;

    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    
    swap(&arr[i + 1], &arr[high]);  
    return i + 1;
}

// The QuickSort function 
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        
       
        int pi = partition(arr, low, high);

        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int arr[100] ;
    int n ;
    printf("enter number of element :");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {

        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
