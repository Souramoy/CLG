#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
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
    int count = 0;
    for (int value : arr)
    {
        cout << "[" << count++ << "] = " << value << endl;
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

    bubbleSort(arr);

    cout << "After the Sorting:" << endl;
    display(arr);

    return 0;
}
