/*Develop a menu driven Program in C for the following operations on Singly Linked List
(SLL) of Student Data with the fields: USN, Name, Programme, Sem,
PhNo
a. Create a SLL of N Students Data by using front insertion.
b. Display the status of SLL and count the number of nodes in it
c. Perform Insertion / Deletion at End of SLL
d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack)
e. Exit
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char usn[20],name[20],prog[10],phno[11];
    int sem;
    struct node *next;
};
typedef struct node* Node;
Node first=NULL,last=NULL;

Node creat()
{
    Node temp;
    temp=(Node)malloc(sizeof(struct node));
    if (temp==NULL){
        printf("\n Memory overflow");
        return first;
    }
    printf("\n enter the usn of students :");
    scanf("%s",temp->usn);
    printf("\n enter the name of students :");
    scanf("%s",temp->name);
    printf("\n enter the program of students :");
    scanf("%s",temp->prog);
    printf("\n enter the phone No. of students :");
    scanf("%s",temp->phno);
    printf("\n enter the sem of students :");
    scanf("%d",&temp->sem);
    temp->next=NULL;
    return temp;
}

Node insert_rear(Node first)
{
    Node temp,last,cur;
    temp=creat();
    cur=first;
    if (first==NULL)
        return temp;
    else
    { 
        while(cur->next!=NULL)
            cur=cur->next;
         cur->next=temp;      
    }     
    return first;
}
Node insert_front(Node first)
{
    Node temp;
    temp=creat();
    if (first==NULL)
        return temp;
    else
        temp->next=first ;  
    return temp;   
}
Node del_rear(Node first)
{
    Node prev,cur;
    cur=first;
    prev=NULL;
    if (first==NULL)
        printf("SLL is empty");
    else if(first->next==NULL)
    {
        printf("\nNode deleted for %s\n",first->name);
        free(first);
        return NULL;
    }
    else
    { 
        while(cur->next!=NULL){
            prev=cur;
            cur=cur->next;
        }
        printf("\nNode deleted for %s\n",cur->name);
        prev->next=NULL;
        free(cur);     
    }     
    return first;
}
Node del_front(Node first)
{
    Node cur;
    cur=first;
    if (first==NULL)
        printf("SLL is empty");
    else
    { 
        printf("\nNode deleted for %s\n",cur->name);
        first=first->next;
        free(cur);     
    }     
    return first;
}
void display(Node first)
{
    Node cur;
    int count = 0;
    if(first==NULL)
    {
        printf("\nSLL is empty\n");
        return;
    }
    cur=first;
    printf("\nUSN\t\tName\tProgram\tSem\tPhone num");
    while(cur!=NULL)
        {
            printf("\n%s\t\t%s\t%s\t%d\t%s",cur->usn, cur->name, cur->prog, cur->sem, cur->phno);
            cur=cur->next;
            count++;
        }
    printf("\n the no. of nodes is : %d",count);
}

int main()
{
    int n,ch;
    printf("enter the number of students :");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        printf("\nEnter Data for Node %d :\n", i+1);
        first=insert_front(first);
    }
    for(;;)
    {
    printf("\nSLL OPERATIONS\n");
    printf("====================");
    printf("\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
    printf("\nEnter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1: first = insert_front(first);
    break;
    case 2: first = insert_rear(first);
    break;
    case 3: first = del_front(first);
    break;
    case 4: first = del_rear(first);
    break;
    case 5: display(first);
    break;
    case 6: exit(0);
    }
    }
}