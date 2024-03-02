/*Develop a menu driven Program in C for the following operations on STACK of Integers
(Array Implementation of Stack with maximum size MAX)
a. Push an Element on to Stack
b. Pop an Element from Stack
c. Demonstrate how Stack can be used to check Palindrome
d. Demonstrate Overflow and Underflow situations on Stack
e. Display the status of Stack
f. Exit
Support the program with appropriate functions for each of the above operations */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

#define MAX 4

int push(int *, int *,int );
int pop(int *, int *);
int peek(int *, int *);
void displayS(int *, int *);
bool IsFull(int *);
bool IsEmpty(int *);
void CkPalindrome();

int main()
{
    int s[MAX];
    int top=-1;
    int choice,element,elem;
    while (1)
    {
        printf("\nSTACK OPERATIONS\n");
	    printf("====================");
	    printf("\n1.Push\n2.Pop\n3.Display\n4.Peek\n5.CheckPalindrome\n6.DemonstarteOverflow\n7.Demonstarte Underflow\n8.EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
        {
            case 1 : if(top==MAX-1)
                        printf("\nStack is full");
                     else {
                        printf("\n enter the elemnet to be added :");
                        scanf("%d",&element);
                        push(s,&top,element);
                     }
                     break;
            case 2 : elem=pop(s,&top);
                    printf("\n deleted element is  : %d",elem);
                    break;
            case 3 : displayS(s,&top);break;
            case 4 : peek(s,&top);break;
            case 5 : CkPalindrome();break;
            case 6 : if (IsFull(&top)==true)
                        printf("\n stack is full");
                      else 
                      printf("\n stack is not full");
                      break;
            case 7 : if (IsEmpty(&top)==true)
                        printf("\n stack is Empty");
                      else 
                      printf("\n stack is not empty ");
                      break;
            case 8 : exit(0);
        }

    }

}

int push(int *s, int *top,int elem )
{
    s[++(*top)]=elem;
}

int pop(int *s, int *top)
{
    if(*top==-1)
        printf("\n Stack is empty ");
    else {
        int elem =s[(*top)--];
        return elem;
        }
}


int peek(int *s, int *top)
{
    if(*top==-1)
        printf("\n Stack is empty ");
    else 
        printf("\n the element at top of stack is : %d", s[*top]);
}
void displayS(int *s, int *top)
{
    if(*top==-1)
        printf("\n Stack is empty ");
    else 
        printf("\n the elements of Stack are :\n ");
        for(int i=0;i<=*top;i++)
            printf("%d\t",s[i]);
}
bool IsFull(int *top)
{
    if(*top==MAX-1)  return true ;
    else return false;
}
bool IsEmpty(int *top)
{
    if(*top==-1)  return true ;
    else return false;
}
void CkPalindrome()
{   
    int num, rev = 0, digit, temp=0;
    int t = -1, stack[MAX];

    printf("Enter a 4-digit number to check for palindrome: ");
    scanf("%d", &num);

    temp = num;
    for (int i = 0; i < MAX; i++)
    {
        digit = temp % 10;
        temp = temp / 10;
        push(stack, &t, digit);
    }
    for (int i = 0; i <= MAX-1;i++ )
    {
        digit = pop(stack, &t);
        
        rev += digit * pow(10, i);
        
    }
   
    if (num == rev)
        printf("%d is a palindrome.\n", num);
    else
        printf("%d is not a palindrome.\n", num);
}

