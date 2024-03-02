#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define STK_SIZE 10

void push(char[], int *, char);
char pop(char[], int *);
int preced(char);

int main()
{
    char inexp[50], postexp[50], stack[10], symb;
    int i = 0, j = 0, top = -1;

    printf("\nEnter the infix expression: ");
    scanf("%s", inexp);

    push(stack, &top, '#');

    for (i = 0; i < strlen(inexp); i++)
    {
        symb = inexp[i];

        if (isalnum(symb))
            postexp[j++] = symb;
        else if (symb == '(')
            push(stack, &top, symb);
        else if (symb == ')')
        {
            while (stack[top] != '(')
            {
                postexp[j++] = pop(stack, &top);
            }
            pop(stack, &top);
        }
        else
        {
            while (preced(stack[top]) >= preced(symb))
            {
                if (stack[top] == '^' && symb == '^')
                    break;
                postexp[j++] = pop(stack, &top);
            }
            push(stack, &top, symb);
        }
    }

    while (stack[top] != '#')
        postexp[j++] = pop(stack, &top);

    postexp[j++] = '\0';

    printf("\nThe infix expression is: %s", inexp);
    printf("\nThe postfix expression is: %s", postexp);

    return 0;
}

void push(char Stack[], int *t, char elem)
{
    *t = *t + 1;
    Stack[*t] = elem;
}

char pop(char Stack[], int *t)
{
    char elem;
    elem = Stack[*t];
    *t = *t - 1;
    return elem;
}

int preced(char ch)
{
    int iPrecdVal;

    switch (ch)
    {
    case '#':iPrecdVal = -1;break;
    case '(': iPrecdVal = 0; break;
    case '+':
    case '-':iPrecdVal = 1; break;
    case '*':
    case '/':
    case '%':iPrecdVal = 2; break;
    case '^':iPrecdVal = 3;break;
    }

    return iPrecdVal;
}
