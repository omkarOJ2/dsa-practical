/*Develop a menu driven Program in C for the following operations on Circular QUEUE of
Characters (Array Implementation of Queue with maximum size MAX)
a. Insert an Element on to Circular QUEUE
b. Delete an Element from Circular QUEUE
c. Demonstrate Overflow and Underflow situations on Circular QUEUE
d. Display the status of Circular QUEUE
e. Exit
Support the program with appropriate functions for each of the above operations
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

#define SIZE 5

void insert(char [], int*, int*, char);
char del(char[], int*, int*);
void display(char [], int, int);
bool qfull(int, int);
bool qempty(int, int);

int main()
{
    char q[SIZE];
    int f = -1, r = -1;
    int ch;
    char elem;
    while(1)
    {
        printf("\nQueue Operations\n");
        printf("=====================");
        printf("\n1.Qinsert\n2.Qdelete\n3.Qdisplay\n4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        getchar();
        switch(ch)
        {
            case 1: if(!qfull(f,r))
                    {
                    printf("\nEnter an element : ");
                    scanf("%c", &elem);
                    insert(q, &f, &r, elem);
                    }
                    else
                    { 
                        printf("\nQueue is Full\n");
                    }
                        break;
            case 2: if(!qempty(f, r))
                    {
                        elem = del(q, &f, &r);
                        printf("\nDeleted element is %c\n", elem);
                    }
                    else
                    {
                        printf("\nQueue is Empty\n");
                    }
                    break;
            case 3: if(!qempty(f, r))
                    {
                        printf("\nContents of the Queue is \n");
                        display(q, f, r);
                    }
                    else
                    {
                        printf("\nQueue is Empty\n");
                    }
                    break;
            case 4: exit(0);
            default: printf("\nInvalid choice\n");
                    break;
        }
    }
    return 0;
}
void insert(char q[], int *f, int*r, char c)
{
    if(*r==-1)
    {
        (*f)++;
        (*r)++;
    }
    else
        *r=(*r+1)%SIZE;
    q[*r]=c;
}
char del(char q[], int *f, int *r)
{
    char elem=q[*f];
    if(*f == *r)
    {
        *f = -1;
        *r = -1;
    }
    else
           *f = (*f + 1)%SIZE;
    
    return elem;
}
bool qfull(int f, int r)
{
    if((r+1) % SIZE == f)
        return true;
    else
        return false;
}
bool qempty(int f, int r)
{
    if(f == -1)
        return true;
    else
        return false;
}
void display(char q[], int f, int r)
{
    if(f==-1)
        {
            printf("\nqueue is Empty\n");
            return ;
        }
    int i=f;
    while(i!=r)
    {
        printf("\n %c",q[i]);
        i=(i+1)%SIZE;
    }
    printf("\n %c",q[r]);
}