#include <iostream>
#include <vector>
using namespace std;

void SeletionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i)
    {
        int min_index = i;
        for (int j = i + 1; j < n; ++j)
        {
            if(arr[j]<arr[min_index]){
                min_index = j; // find min index which contain small element.
            }
        }

        swap(arr[i], arr[min_index]);
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

    SeletionSort(arr);

    cout << "After the Sorting:" << endl;
    display(arr);

    return 0;
}
