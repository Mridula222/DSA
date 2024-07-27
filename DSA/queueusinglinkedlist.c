#include <stdio.h>
#include <stdlib.h>

void insert();
void delete();
void display();
struct node
{
    int info;
    struct node *next;
};
struct node *front = NULL, *rear = NULL;
int main()
{
    int choice;
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
            printf("invalid choice\n");
        }
    }
}
void insert()
{ // insert at end
    struct node *newnode, *temp;
    int item;
    temp = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("queue overflow\n");
    }
    else
    {
        printf("enter the value to insert");
        scanf("%d", &item);
        temp->info = item;
        temp->next = NULL;
        if (rear == NULL)
        {
            rear = temp; // insertion for first time
            front = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
}
void delete()
{ // delete from beg
    struct node *temp;
    if (front == NULL)
    {
        printf("queue underflow\n");
    }
    else
    {
        temp = front;
        printf("deleted value is %d", temp->info);
        front = front->next;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    if (front == NULL)
    {
        printf("queue underflow");
    }
    else
    {
        temp = front;
        printf("values of queue are:");
        while (temp != NULL)
        {
            printf("%d\t", temp->info);
            temp = temp->next;
        }
    }
}
