#include <stdio.h>
#include <string.h>
int stack[50], top = -1;
char push(char);
char pop(char);
int main()
{
    char str[50], ch;
    int i, l;
    printf("enter the string");
    gets(str);
    l = strlen(str);
    for (i = 0; i < l; i++)
    {
        ch = push(str[i]);
    }
    printf("reverse of a string");
    for (i = 0; i < l; i++)
    {
        ch = pop(str[i]);
        printf("%c", ch);
    }
}
char push(char ch)
{
    top++;
    stack[top] = ch;
}
char pop(char ch)
{
    ch = stack[top];
    top--;
    return ch;
}