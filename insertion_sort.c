// C program for implementation of Insertion Sort
#include <stdio.h>


void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver method
int main()
{
    int arr[100];
    int n;
    printf("enter number of element :");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {

        scanf("%d", &arr[i]);
    } 

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}


