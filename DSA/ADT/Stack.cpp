#include <iostream>
using namespace std;

#define MAX_SIZE 5
#define MIN_SIZE -1
int topIndex = -1;     
int myStack[MAX_SIZE]; 


bool isEmpty();
bool isFull();
int peek();

void push(int data)
{
    if (isFull())
    {
        cout << "Push is not possible!" << endl;
        return;
    }
    myStack[++topIndex] = data;
    cout << "Data pushed in stack!" << endl;
}

void pop()
{
    if (isEmpty())
    {
        cout << "Stack is Empty!" << endl;
        return;
    }
    cout << myStack[topIndex--] << " Popped from stack!" << endl;
}

bool isEmpty()
{
    return topIndex == MIN_SIZE;
}

bool isFull()
{
    return topIndex == MAX_SIZE - 1;
}

int peek()
{
    return topIndex;
}

void display()
{
    if (isEmpty())
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    for (int i = 0; i <= topIndex; i++)
    {
        cout << myStack[i] << " ";
    }
    cout << endl;
}

int main()
{
    push(1);
    push(2);
    push(8);
    display();
    pop();
    display();
    return 0;
}
