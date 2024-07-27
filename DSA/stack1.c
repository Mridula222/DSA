#include <stdio.h>
#include <stdlib.h>
int stack[5];
int top = -1;
void push();
void pop();
void peek();
void display();
void main()
{
    int choice;
    do
    {
        printf("enter choice 1.push 2.pop 3.peek 4.display");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        default:
            printf("invalid character");
        }
    } while (choice != 0);
    printf("%c", choice);
}
void push()
{
    int x;
    printf("enter data");
    scanf("%d", &x);
    if (top == 4)
    {
        printf("overflow");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
void pop()
{
    int item;
    if (top == -1)
    {
        printf("underflow");
    }
    else
    {
        item = stack[top];
        top--;
        printf("popped item is %d", item);
    }
}
void peek()
{
    if (top == -1)
    {
        printf("empty stack");
    }
    else
    {
        printf("%d", stack[top]);
    }
}
void display()
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("%d", stack[i]);
    }
}