#include <stdio.h>

int a[100];
int top = -1;
int front = -1, rear = -1,count=0;

void push(int item)
{
    if (top == 100 - 1)
    {
        printf("the stack is full \n");
    }

    else
    {

        top = top + 1;
        a[top] = item;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("the stack is empty \n");
    }
    else
    {
        printf("the deleted element is %d\n", a[top]);
        top = top - 1;
    }
}

void display()
{

    if (top != -1)
    {
        for (int i = top; i >= 0; i--)
        {
            printf(" \n%d \n", a[i]);
        }
    }

    else
    {
        printf("stack is empty");
    }
}
void insertQ(int item)
{
    if (rear == 50 - 1)
        printf("Q is full \n");

    else
    {
        rear = rear + 1;
        a[rear] = item;
    }
}

void deleteQ()
{
    if (rear == front)
        printf("Q is empty \n");
    else
    {
        front = front + 1;
        printf("the deleted element is %d \n", a[front]);
    }
}

void displayQ()
{
    if (rear == front)
        printf("Q is empty \n");
    else
    {

        for (int i = front + 1; i <= rear; i++)
            printf("%d \t", a[i]);
    }
}


void insertCQ(int item)
{
    if(front==rear&&count==1)
    printf("Q is full \n ");

    else{
        a[rear]=item;
        rear =(rear+1)%100;
        count=1;
    }
}
void deleteCQ()
{
    if (front==rear && count==0){
        printf("Q is empty \n");
    }
    else
    {
        printf("the deleted element is %d \n", a[front]);
        front=(front+1)%100;
        count=0;
    }
}

void displayCQ()
{
    if (rear == front&& count==0)
        printf("Q is empty \n");
    else
    {

        for (int i = front ; i <= rear-1; i++)
            printf("%d \t", a[i]);
    }
}

int main()
{
    int choice;
    int stack, item, out_1 = 0,queue,cqueue;
    printf("enter 1 for stack|| 2 for Q|| and enter 3 for Circular Q");
    scanf("%d", &choice);
    while (out_1 == 0)
    {
        if (choice == 1)
        {

            printf("Enter 1 to push|| enter 2 to pop|| enter 3 to display|| Enter 4 to exit");

            scanf("%d", &stack);
            switch (stack)
            {
            case 1:

                printf("\n enter item to push");
                scanf("%d", &item);

                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                out_1 = 1;  
                break;

            default:
                printf("\n wrong input ");
                break;
            }
        }
        else if (choice == 2)
        {
                    printf("\n Enter 1 to insertQ|| enter 2 to deleteQ|| enter 3 to display|| Enter  4 to exit");

            scanf("%d", &queue);
            switch (queue)
            {
            case 1:
                printf("\n enter item to insert \n");
                scanf("%d", &item);
                insertQ(item);

                break;
            case 2:
                deleteQ();
                break;
            case 3:
                displayQ();
                break;

            case 4:
                out_1 = 1;

                break;
            default:
                printf("\n wrong choice ");
                break;
            }
        }

        else if (choice == 3)
        {
            printf("\n Enter 1 to insertCQ|| enter 2 to deleteCQ|| enter 3 to display|| Enter  4 to exit");

            scanf("%d", &cqueue);
            switch (cqueue)
            {
            case 1:
                printf("\nenter item to insert \n");
                scanf("%d", &item);
                insertCQ(item);

                break;
            case 2:
                deleteCQ();
                break;
            case 3:
                displayCQ();
                break;

            case 4:
                out_1 = 1;

                break;
            default:
                printf("\n wrong choice ");
                break;
            }  
        }

        else
        {
            printf("/nWrong Choice");
            break;
        }
    }

    return 0;
}