#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); ++i)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertData(vector<int> &arr, int limit)
{
    int value;
    if (limit < 1)
    {
        cout << "Invalid index provided, must be at least 1 or larger." << endl;
        return;
    }

    for (int i = 0; i < limit; i++)
    {
        cout << "Enter the Data: ";
        cin >> value;
        arr.push_back(value);
    }
}

void display(const vector<int> &arr)
{
    for (int value : arr)
    {
        cout << "Data is " << value << endl;
    }
}

int main()
{
    vector<int> arr;
    int n;

    cout << "Enter the array size: ";
    cin >> n;
    
    insertData(arr, n);

    cout << "Before the Sorting:" << endl;
    display(arr);

    insertionSort(arr);

    cout << "After the Sorting:" << endl;
    display(arr);

    return 0;
}
