#include <stdio.h>

int a[100];

int front = -1, rear = -1;

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

int main(){


      int queue,item;
      int out =0;
        while (out==0)
        {
           
            printf("\n Enter 1 to insertQ|| enter 2 to deleteQ|| enter 3 to display || enter 4 to exit:  ");

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
                out  = 1;
                break;

            default:
                printf("\n wrong choice ");
                break;
         
            }
        }
        







    return 0;
}