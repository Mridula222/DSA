#include <stdio.h>
#include <stdlib.h>
void insert();
void delete();
void display();

int queue[50], size, rear = -1, front = -1;
int main()
{
    int choice;
    printf("Enter size\n");
    scanf("%d", &size);
    while (1)
    {
        printf("1.insert\n2.delete\n3.display\n");
        printf("enter choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                insert();
            break;
            case 2:
                delete ();
            break;
            case 3:
                display();
            break;
            default:
                 printf("wrong choice");
        }
    }
}
void insert()
{
    int item;
    if (rear == size-1)
    {
        printf("queue overflow");
    }
    else
    {
        printf("enter the value to insert");
        scanf("%d", &item);
        if (rear==-1)
        {
            front++;
        }
        rear++; // in this case if no data is there then for first time both r and f will be o
        queue[rear] = item;
    }
}
void delete()
{
    if ((front == -1) || (front == rear + 1))
    {
        printf("\n queue underflow");
    }
    else
    {
        printf("deleted value =%d", queue[front]);
        front++;
    }
}
void display()
{
    int index;
    if ((front == -1) || front == rear + 1)
    {
        printf("queue underflow");
    }
    else
    {
        printf("elements of queue are");
        for (index = front; index <= rear; index++)
        { // element is not always present at 0th index
            printf("%d", queue[index]);
        }
    }
}