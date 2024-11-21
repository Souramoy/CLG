#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int data)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == data)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    const int size = 5;
    int arr[size] = {7, 8, 9, 10, 11};
    int choice, data;

    cout << "Enter the data to search: ";
    cin >> data;

    cout << "Choose the search method:\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search\n";
    cin >> choice;

    int result;
    if (choice == 1)
    {
        result = linearSearch(arr, size, data);
        if (result != -1)
            cout << "Data found at index " << result << " using Linear Search." << endl;
        else
            cout << "Data not found using Linear Search." << endl;
    }
    else if (choice == 2)
    {
        result = binarySearch(arr, 0, size - 1, data);
        if (result != -1)
            cout << "Data found at index " << result << " using Binary Search." << endl;
        else
            cout << "Data not found using Binary Search." << endl;
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
