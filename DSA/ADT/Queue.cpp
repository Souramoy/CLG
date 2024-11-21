#include <iostream>
#include <vector>
using namespace std;

void enque(vector<int> &queue, int data)
{
    queue.push_back(data);
}

void dque(vector<int> &queue)
{
    if (!queue.empty())
    {
        queue.erase(queue.begin());
    }
    else
    {
        cout << "Deletion is not possible!" << endl;
    }
}

void display(const vector<int> &queue)
{
    for (auto value : queue)
    {
        cout << value << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> queue;
    enque(queue, 10);
    enque(queue, 20);
    enque(queue, 30);

    cout << "Queue after enqueuing elements: ";
    display(queue);

    dque(queue);
    cout << "Queue after dequeuing an element: ";
    display(queue);

    return 0;
}
