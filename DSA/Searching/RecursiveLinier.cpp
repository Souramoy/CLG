#include <iostream>
#include <vector>
using namespace std;

int RecursiveLinierSearch(vector<int> &arr, int target, int count)
{
    if (count >= arr.size())
    {
        return -1;
    }
    if (target == arr[count])
    {
        return count;
    }
    return RecursiveLinierSearch(arr, target, count + 1);
}

void RecursvieInput(vector<int> &arr, int limit)
{
    if (limit == 0)
    {
        return;
    }
    int value;
    cout << "Enter the data: ";
    cin >> value;
    arr.push_back(value);
    RecursvieInput(arr, limit - 1);
}

int main()
{
    vector<int> arr;
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;
    RecursvieInput(arr, n);

    cout << "Enter the target element: ";
    cin >> target;

    int result = RecursiveLinierSort(arr, target, 0);
    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}
