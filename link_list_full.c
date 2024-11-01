#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void display(struct Node *node)
{
    if (node == NULL)
        printf("empty linked list!");
    else
    {

        // as linked list will end when Node is Null
        while (node != NULL)
        {
            printf("%d ", node->data);
            node = node->next;
            printf("--->");
        }
    }
}

int searchElement(struct Node *head, int item)
{
    if (head == NULL)
        printf("list is empty !");
    else
    {
        struct Node *current = head; // Initialize current
        int index = 0;
        // traverse till then end of the linked list
        while (current != NULL)
        {
            if (current->data == item)
            {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }
}
void deleteNode(struct Node **head_ref, int key)
{
    if (head_ref == NULL)
        printf("list is empty !");
    else
    {
        // Store head node
        struct Node *temp = *head_ref, *prev;

        if (temp != NULL && temp->data == key)
        {
            *head_ref = temp->next; // Changed head
            free(temp);             // free old head
            return;
        }

        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        // If key was not present in linked list
        if (temp == NULL)
            return;

        // Unlink the node from linked list
        prev->next = temp->next;

        free(temp); // Free
    }
}
struct Node *push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);

    return new_node;
}

struct Node * append(struct Node **head_ref, int new_data)
{

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    struct Node *last = *head_ref;

    /* 2. put in the data */
    new_node->data = new_data;

    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return *head_ref;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;
    return *head_ref;
}

int main()
{
    int item;
    int d, del;
    int index;

    struct Node *head = NULL;
    struct Node *node2 = NULL;
    struct Node *node3 = NULL;
    struct Node *node4 = NULL;

    head = (struct Node *)malloc(sizeof(struct Node));
    node2 = (struct Node *)malloc(sizeof(struct Node));
    node3 = (struct Node *)malloc(sizeof(struct Node));
    node4 = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = node2;
    node2->data = 15;
    node2->next = node3;

    node3->data = 20;
    node3->next = node4;

    node4->data = 25;
    node4->next = NULL;

    int input;
    printf(" \nenter 1 to insert at front || enter 2 to insert at end || enter 3 to search elemnt || enter 4 to delete element || enter 5 to display || enter 6 to exit    :: ");
    scanf("%d", &input);
    switch (input)
    {
    case 1:
        printf("enter new node : ");
        scanf("%d", &d);
        head = push(&head, d);
        printf(" \nCreated Linked List:\n ");
        display(head);
        main();
        break;
    case 2:
        printf("enter new node : ");
        scanf("%d", &d);
        head = append(&head, d);
        printf(" \nCreated Linked List:\n ");
        display(head);
        main();
        break;
    case 3:
        printf("enter the item");
        scanf("%d", &item);
        index = searchElement(head, item);

        if (index == -1)
            printf("Item not found");
        else
            printf("Item found at position: %d", index + 1);
        main();
        break;

    case 4:
        printf(" \n\n enter node to delete : ");
        scanf("%d", &del);
        deleteNode(&head, del);
        printf(" \nlinked list after deletion :\n ");
        display(head);
        main();
        break;
    case 5:
        display(head);
        main();
        break;
    case 6:
        break;
    default:
    printf("worng input ");
        break;
    }

    return 0;
}