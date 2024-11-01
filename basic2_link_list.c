#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *push(struct Node *head, int data)
{
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->next = head;
    return new;
}
struct Node *append(struct Node *head, int data)
{
    struct Node *new;
    struct Node *temp = head;
    new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        while (head != NULL)
        {
            if (temp->next == NULL)
            {
                temp->next = new;
                break;
            }
            temp = temp->next;
        }
    }
    return head;
}
int search(struct Node *head, int key)
{
    int pos = 1;
    struct Node *temp = head;
    if (head == NULL)
    {
        printf(" The link is empty !!!");
        return 0;
    }

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Node found at position %d", pos);
            return 0;
        }
        pos++;
        temp = temp->next;
    }
    printf("Item not found !!!!");
    return 0;
}
struct Node *delete(struct Node *head, int key)
{
    struct Node *temp = head;
    struct Node *prev = temp;
    struct Node *aft = temp->next;
    if (head == NULL)
    {
        printf(" \nthe link is empty cannot perform delete now \n ");
        return head;
    }
    if (head->data == key)
    {
        head = aft;
        free(temp);
        return head;
    }
    if (temp->next == NULL && temp->data == key)
    {
        prev->next = NULL;
        free(temp);
        return head;
    }

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            prev->next = aft;
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
        aft = temp->next;
    }
    printf("Node not found in the list ");
    return head;
}
struct Node *insert(struct Node *head, int data, int key)
{
    struct Node *temp = head;
  
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    if (temp->next == NULL && temp->data == key)
    {
        temp->next = new;
        new->next = NULL;
        return head;
    }
    while (temp!=NULL)
    {
        if(temp->data==key){
            new->next=temp->next;
            temp->next=new;
            
            return head;
        }
      
        temp=temp->next;
        
    }
    printf("wrong choice of position !!!");
    return head;
}
void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf(" \t%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    struct Node *head = NULL;
    int data = 0;
    int key;
    while (1)
    {
        int x;
        printf("print option ");
        scanf("%d", &x);

        if (x == 1)
        {
            printf(" \n\nenter the data ");
            scanf("%d", &data);
            if (data == -1)
            {
                break;
            }
            head = push(head, data);
            display(head);
        }
        else if (x == 2)
        {
            printf(" \nenter the data ");
            scanf("%d", &data);
            if (data == -1)
            {
                break;
            }
            head = append(head, data);
            display(head);
        }
        else if (x == 3)
        {
            printf(" \nenter the key ");
            scanf("%d", &data);
            if (data == -1)
            {
                break;
            }
            search(head, data);
        }
        else if (x==4)
        {
            printf(" \nenter the key ");
            scanf("%d", &data);
            if (data == -1)
            {
                break;
            }
            head = delete (head, data);
            display(head);
        }
        else if(x==5)
        {
            printf(" \nenter the key ");
            scanf("%d", &key);
            printf(" \nenter the data ");
            scanf("%d", &data);

            if (data == -1)
            {
                break;
            }
            head = insert(head, data,key);
            display(head);
        }
    }

    return 0;
}
