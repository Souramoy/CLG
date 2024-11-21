#include <iostream>
using namespace std;

void insert(int arr[], int &size, int max_size, int index, int data)
{
    if (index > size || index < 0) 
    {
        cout << "Index out of Range!" << endl;
        return;
    }

    if (size >= max_size) 
    {
        cout << "Array is full!" << endl;
        return;
    }

    for (int i = size; i > index; --i)
    {
        arr[i] = arr[i - 1];
    }

    arr[index] = data;
    size++;
    cout << "Insertion Successful!" << endl;
}

void update(int arr[], int size, int index, int data)
{
    if (index >= size || index < 0)
    {
        cout << "Index out of Range!" << endl;
    }
    else
    {
        arr[index] = data;
        cout << "Updation Successful!" << endl;
    }
}

void traversal(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " at index " << i << endl;
    }
}

void deletion(int arr[], int &size, int index)
{
    if (index >= size || index < 0)
    {
        cout << "Index out of Range!" << endl;
        return;
    }

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "Deletion Successful!" << endl;
}

int main()
{
    int arr[10] = {10, 12, 7, 8, 15}; 
    int length = 5;                   \

    cout << "Initial Array:" << endl;
    traversal(arr, length);

    insert(arr, length, 10, 2, 5); 
    cout << "After Insertion:" << endl;
    traversal(arr, length);

    deletion(arr, length, 2); 
    cout << "After Deletion:" << endl;
    traversal(arr, length);

    return 0;
}
