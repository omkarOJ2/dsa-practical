#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void push(int *Stack, int *t, int elem);
int pop(int *Stack, int *t);

int main()
{
    int i = 0, op1, op2, top = -1, res = 0, stack[50] = {0};
    char postexp[50], symb;
    
    printf("Enter the postfix expression: ");
    scanf("%s", postexp);
    
    for (i = 0; i < strlen(postexp); i++)
    {
        symb = postexp[i];
        if (isdigit(symb))
            push(stack, &top, symb - '0');  
        else
        {
            op2 = pop(stack, &top);
            op1 = pop(stack, &top);
            switch (symb)
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/': res = op1 / op2;
                
                break;
            case '^':
                res = (int)pow(op1, op2);
                break;
            }
            push(stack, &top, res);
        }
    }
    res = pop(stack, &top);
        printf("\nValue of %s expression is %d\n", postexp, res);
    return 0;
}

void push(int *Stack, int *t, int elem)
{
        Stack[++(*t)] = elem;
}

int pop(int *Stack, int *t)
{
    return Stack[(*t)--];
}
