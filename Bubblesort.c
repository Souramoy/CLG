// soting an array
#include <stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSorta(int arr[], int n)
{
    int i, j;
    int count = 0;
    for (i = 0; i < n - 1; i++)
    {
         count = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                count = 1;
            }
        }

        if (count == 0)
            break;
    }
}
void bubbleSortd(int arr[], int n)
{
    int i, j;
    int count = 0;
    for (i = 0; i < n - 1; i++)
    {
         count = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                count = 1;
            }
        }

        if (count == 0)
            break;
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int arr[100], n, i, type;
    printf("enter number of element :");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {

        scanf("%d", &arr[i]);
    }
    printf("for ascending press 1 for desending press 2");
    scanf("%d", &type);
    switch (type)
    {
    case 1:
        bubbleSorta(arr, n);
        break;
    case 2:
        bubbleSortd(arr, n);
        break;

    default:
        printf("wrong choice ");
        break;
    }

    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
