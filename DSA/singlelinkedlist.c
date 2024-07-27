#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *start = NULL;
void traverse();
void insertbegin();
void insertend();
void insertloc();
void deletebeg();
void deleteend();
void deletelocation();
int main()
{
    int choice;
    while (1)
    {
        printf("1.traversal\n2.insertbegin\n3.insertend\n4.insertloc\n5.deletebeg\n6.deleteend\n7.deletelocation");
        printf("enter your choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            traverse();
            break;
        case 2:
            insertbegin();
            break;
        case 3:
            insertend();
            break;
        case 4:
            insertloc();
            break;
        case 5:
            deletebeg();
            break;
        case 6:
            deleteend();
            break;
        case 7:
            deletelocation();
            break;
        default:
            printf("wrong choice");
        }
    }
    return choice;
}
void traverse()
{
    struct node *temp;
    if (start == NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp = start;
        printf("values are:");
        while (temp != NULL)
        {
            printf("%d\t", temp->info);
            temp = temp->next;
        }
    }
}
void insertbegin()
{
    struct node *newnode;
    int item;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("memory is not allocated\n");
    }
    else
    {
        printf("enter the value to insert\n");
        scanf("%d", &item);
        newnode->info = item;
        newnode->next = NULL;
    }
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        newnode->next = start;
        start = newnode;
    }
}
void insertend()
{
    struct node *newnode, *temp;
    int item;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("memory not allocated");
    }
    else
    {
        printf("enter the value to insert");
        scanf("%d", &item);
        newnode->info = item;
        newnode->next = NULL;
        if (start == NULL)
        {
            start = newnode;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}
void insertloc()
{
    struct node *newnode, *temp, *ptr;
    int item, loc, count = 1;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("memory not allocated");
    }
    else
    {
        printf("enter the value to insert");
        scanf("%d", &item);
        newnode->info = item;
        newnode->next = NULL;
    }
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        printf("enter the location at which you want to insert\n");
        scanf("%d", &loc);
        temp = start;
        while (temp != NULL && count != loc)
        {
            count++;
            ptr = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("memory not allocated");
        }
        else
        {
            ptr->next = newnode;
            newnode->next = temp;
        }
    }
}
void deletebeg()
{
    struct node *temp;
    if (start == NULL)
    {
        printf("memory not allocated\n");
    }
    else
    {
        temp = start;
        start = start->next;
        printf("deleted value is %d", temp->info);
        free(temp);
    }
}
void deleteend()
{
    struct node *temp, *ptr;
    if (start == NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp = start;
        if (start == NULL)
        {
            printf("memory not allocated");
        }
        else
        {
            temp = start;
            if (start->next == NULL)
            {
                start = NULL;
            }
            else
            {
                while (temp->next != NULL)
                {
                    ptr = temp;
                    temp = temp->next;
                }
                ptr->next = NULL;
            }
            printf("deleted value is %d", temp->info);
            free(temp);
        }
    }
}
void deletelocation()
{
    struct node *temp, *ptr;
    int item, count = 1, loc;
    if (start == NULL)
    {
        printf("memory not allocated");
    }
    else
    {
        temp = start;
        if (start->next == NULL)
        {
            start = NULL;
            printf("delted value is %d", temp->info);
            free(temp);
        }
        else
        {
            printf("enter the location from which you want to delete\n");
            scanf("%d", &loc);
            if (loc == 1)
            {
                start = start->next;
                printf("%d", temp->info);
                free(temp);
            }
            else
            {
                while (temp != NULL && count != loc)
                {
                    ptr = temp;
                    temp = temp->next;
                    count++;
                }
                if (temp == NULL)
                {
                    printf("node is not present\n");
                }
                else
                {
                    ptr->next = temp->next;
                    printf("deleted value is %d", temp->info);
                    free(temp);
                }
            }
        }
    }
}