#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class List
{
private:
    Node *head;
    static int count = 0;

public:
    List()
    {
        head = NULL;
    }

    // Destructor to deallocate memory
    ~List()
    {
        Node *current = head;
        while (current != NULL)
        {
            Node *nextNode = current->next;
            delete current;     // Delete the current node
            current = nextNode; // Move to the next node
        }
        head = NULL; // Set head to NULL for safety
    }

    void createNode(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->next = this->head;
        this->head = newNode;
    }

    void deleteNode(int index)
    {
  
        if (index < 0 || index >= count)
        {
            cout << "Index out of Bound!" << endl;
            return;
        }

        Node *temp = this->head;

        if (index==0)
        {
            head = head->next; 
            delete temp;       
            count--;          
            return;
        }

        for (int i = 0; i < index-1; i++)
        {
            temp = temp->next;
        }

        Node *DeleteNode = temp->next;
        temp = temp->next->next;
        delete DeleteNode;
        count--;
    }

    void display()
    {
        Node *temp = this->head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    List Root;
    Root.createNode(1);
    Root.createNode(2);
    Root.createNode(3);

    Root.display();

    Root.deleteNode(1)
    return 0; // Destructor is called automatically here to free memory
}