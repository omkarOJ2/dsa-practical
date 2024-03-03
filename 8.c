/*Develop a menu driven Program in C for the following operations on Doubly Linked List
(DLL) of Employee Data with the fields: SSN, Name, Dept, Designation,
Sal, PhNo
a. Create a DLL of N Employees Data by using end insertion.
b. Display the status of DLL and count the number of nodes in it
c. Perform Insertion and Deletion at End of DLL
d. Perform Insertion and Deletion at Front of DLL
e. Demonstrate how this DLL can be used as Double Ended Queue.
f. Exit

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char ssn[20],name[20],dep[10],phno[11],desig[15];
    int sal;
    struct node *next,*prev;
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
    printf("\n enter the ssn of employee :");
    scanf("%s",temp->ssn);
    printf("\n enter the name of employee :");
    scanf("%s",temp->name);
    printf("\n enter the department of employee :");
    scanf("%s",temp->dep);
    printf("\n enter the degignation  of employee :");
    scanf("%s",temp->desig);
    printf("\n enter the phone No. of employee :");
    scanf("%s",temp->phno);
    printf("\n enter the sallery of employee :");
    scanf("%d",&temp->sal);
    temp->next=NULL;
    temp->prev=NULL;

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
         temp->prev=cur;     
    }     
    return first;
}
Node insert_front(Node first)
{
    Node temp;
    temp=creat();
    if (first==NULL)
        return temp;
    else{
        temp->next=first ;
        first->prev=temp;
    }  
    return temp;   
}
Node del_rear(Node first)
{
    Node nprev,cur;
    cur=first;
    nprev=NULL;
    if (first==NULL)
        printf("DLL is empty");
    else if(first->next==NULL)
    {
        printf("\nNode deleted for %s\n",first->name);
        free(first);
        return NULL;
    }
    else
    { 
        while(cur->next!=NULL){
            cur=cur->next;
        }
        nprev=cur->prev;
        printf("\nNode deleted for %s\n",cur->name);
        nprev->next=NULL;
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
        first->prev=NULL;
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
    printf("\nUSN\t\tName\tDepartment\tdesignation\tSallary\tPhone num");
    while(cur!=NULL)
        {
            printf("\n%s\t\t%s\t%s\t%s\t%d\t%s",cur->ssn, cur->name, cur->dep,cur->desig, cur->sal, cur->phno);
            cur=cur->next;
            count++;
        }
    printf("\n the no. of nodes is : %d",count);
}

int main()
{
    int n,ch;
    printf("enter the number of employee :");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        printf("\nEnter Data for Node %d :\n", i+1);
        first=insert_rear(first);
    }
    for(;;)
    {
    printf("\nDLL OPERATIONS\n");
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