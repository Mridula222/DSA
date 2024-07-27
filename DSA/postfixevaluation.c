#include <stdio.h>
void sum();
void diff();
void mult();
void div();
void power();
int stack[50], top = -1;
int main()
{
    char st[30];
    int i = 0;
    printf("enter the postfix expression");
    scanf("%[^\n]s", st);
    for (i = 0; st[i] != '\0'; i++)
    {
        if (st[i] != ' ')
        {
            switch (st[i])
            {
            case '+':
                sum();
                break;
            case '-':
                diff();
                break;
            case '*':
                mult();
                break;
            case '/':
                div();
                break;
            case '^':
                power();
                break;
            default:
                top++;
                stack[top] = st[i] - 48;
            }
        }
    }
    printf("\n the result is %d", stack[top]);
}
void sum()
{
    int result, op1, op2;
    op1 = stack[top];
    top--;
    op2 = stack[top];
    top--;
    result = op2 + op1;
    top++;
    stack[top] = result;
}
void diff()
{
    int result, op1, op2;
    op1 = stack[top];
    top--;
    op2 = stack[top];
    top--;
    result = op2 - op1;
    top++;
    stack[top] = result;
}
void mult()
{
    int result, op1, op2;
    op1 = stack[top];
    top--;
    op2 = stack[top];
    top--;
    result = op2 * op1;
    top++;
    stack[top] = result;
}
void div()
{
    int result, op1, op2;
    op1 = stack[top];
    top--;
    op2 = stack[top];
    top--;
    result = op2 / op1;
    top++;
    stack[top] = result;
}
void power()
{
    int res = 1, op1, op2, i;
    op1 = stack[top];
    top--;
    op2 = stack[top];
    top--;
    for (i = 0; i < op1; i++)
    {
        res = res * op2;
    }
    top++;
    stack[top] = res;
}