#include <stdio.h>
#include <stdlib.h>

void insert();
void delete();
void display();
int queue[50], size, rear = -1, front = -1;
int main()
{
    int choice;
    printf("enter the size");
    scanf("%d", &size);
    while (1)
    {
        printf("1.insert\n2.delete\n3.display");
        printf("enter your choice");
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
            printf("invalid choice");
        }
    }
}
void insert()
{
    int item;
    if ((rear == size - 1 && front == 0) || (front == rear + 1))
    {
        printf("queue overflow");
    }
    else
    {
        printf("enter the element");
        scanf("%d", &item);
        if (rear == -1)
        { // insertion for 1st time
            front++;
            rear++;
        }
        else if (rear == size - 1)
        { // if rear is pointing to last index then manually make it zero
            rear = 0;
        }
        else
        {
            rear++; // for rest of case
        }
        queue[rear] = item; // keep value of rear where index is pointing
    }
}
void delete()
{
    if (front == -1)
    { // queue is empty
        printf("queue underflow");
    }
    else
    {
        printf("deleted item is %d", queue[front]);
        if (rear == front)
        { // checking whether it is single element or not
            front = -1;
            rear = -1; // intialize both front and rear with -1
        }
        else if (front == size - 1)
        {              // pointing to last index
            front = 0; // we will manually give value 0
        }
        else
        {
            front++;
        }
    }
}
void display()
{
    int index;
    if ((front == -1))
    {
        printf("queue underflow");
    }
    else
    {
        printf("elements of queue are");
        if (front <= rear)
        { // shows you are in linear queue
            for (index = front; index <= rear; index++)
            {
                printf("%d\t", queue[index]);
            }
        }
        else
        { // circular queue
            for (index = front; index <= size; index++)
            {
                printf("%d\t", queue[index]);
            }
            for (index = 0; index <= rear; index++)
            {
                printf("%d\t", queue[index]);
            }
        }
    }
}