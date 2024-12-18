#include <stdio.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char item)
{
    stack[++top] = item;
}

char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int precedence(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    case '^':
        return 4;
    case '(':
    case ')':
    case '#':
        return 1;
    }
}

int main()
{
    char infix[SIZE], postfix[SIZE], item, temp;
    int i = 0, j = 0;

    printf("Enter infix expression : ");
    scanf("%s", infix);

    push('#');

    while ((item = infix[i++]) != '\0')
    {
        if (item == '(')
            push(item);
        else if (isalnum(item))
            postfix[j++] = item;
        else if (item == ')')
        {
            while ((temp = pop()) != '(')
                postfix[j++] = temp;
        }
        else
        {
            while (precedence(stack[top]) >= precedence(item))
                postfix[j++] = pop();
            push(item);
        }
    }

    while ((temp = pop()) != '#')
        postfix[j++] = temp;

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}