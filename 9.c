/*Develop a Program in C for the following operationson Singly Circular Linked List (SCLL)
with header nodes
a. Represent and Evaluate a Polynomial P(x,y,z) = 6x2y2z-4yz5+3x3yz+2xy5z-2xyz3
b. Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) and store the
result in POLYSUM(x,y,z)
Support the program with appropriate functions for each of the above operations*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

struct node
{
    int cf,px,py,pz;
    struct node *next;
};
typedef struct node* Node;

Node insert(Node poly,int cf,int px,int py,int pz)
{
    Node temp,cur;
    temp=(Node)malloc(sizeof(struct node));
    temp->cf=cf;
    temp->px=px;
    temp->py=py;
    temp->pz=pz;
    temp->next=NULL;
    cur=poly;
    if (poly->next==poly){
        poly->next=temp;
        temp->next=poly;
        return poly;
    }
    else
    { 
        while(cur->next!=poly)
            cur=cur->next;
         cur->next=temp; 
         temp->next=poly ;    
    }     
    return poly;
}
void display(Node poly)
{
    if(poly->next==poly){
        printf("\n polynomial is empty ");
        return ;
    }
    Node cur=poly->next;
    do
    {
        printf("%dx^%dy^%dz^%d ", cur->cf, cur->px, cur->py, cur->pz);
        cur = cur->next;
        if (cur != poly)
            {
            printf("+ ");
            }
    } while (cur != poly);
    printf("\n");
    
}

int evaluate(Node poly, int x, int y, int z)
{   
    int result = 0;
    if (poly->next == poly)
        {
            return result;
        }
    Node cur = poly->next;
    do
    {
        int termValue = cur->cf;
        termValue *= pow(x, cur->px);
        termValue *= pow(y, cur->py);
        termValue *= pow(z, cur->pz);
        result += termValue;
        cur = cur->next;
    } while (cur != poly);
    return result;
}

bool match(Node c1,Node c2)
{
    if(c1->px==c2->px && c1->py==c2->py && c1->pz==c2->pz  )
        return true;
    return false;
}

Node add(Node poly1,Node poly2, Node polySum)
{
    Node cur1 = poly1->next;
    Node cur2 = poly2->next;
    do
    {
        polySum=insert(polySum,cur1->cf,cur1->px,cur1->py,cur2->pz);
        cur1=cur1->next;
    } while(cur1 != poly1);
    do
    {
        cur1 = polySum->next;
        bool m= false;
        do
        {
            if(match(cur1, cur2))
            {
                cur1->cf += cur2->cf;
                m= true;
                break;
            }
            cur1 = cur1->next;
        } while(cur1 != polySum);
        if(!m)
        {
            polySum = insert(polySum, cur2->cf, cur2->px, cur2->py, cur2->pz);
        }
        cur2 = cur2->next;
    } while(cur2 != poly2);
        return polySum;
}

int main()
{
    Node poly1 = (Node)malloc(sizeof(struct node));
    poly1->next = poly1;
    Node poly2 = (Node)malloc(sizeof(struct node));
    poly2->next = poly2;
    Node polySum = (Node)malloc(sizeof(struct node));
    polySum->next = polySum;
    poly1 = insert(poly1, 6, 2, 2, 1);
    poly1 = insert(poly1, 4, 0, 1, 5);
    poly1 = insert(poly1, 3, 3, 1, 1);
    poly1 = insert(poly1, 2, 1, 5, 1);
    poly1 = insert(poly1, 2, 1, 1, 3);
    // Display the polynomial P(x, y, z)
    printf("POLY1(x, y, z) = ");
    display(poly1);

    // Read and evaluate the second polynomial POLY2(x, y, z)
    // Represent the polynomial P(x, y, z) = xyz + 4x^3yz
    poly2 = insert(poly2, 1, 1, 1, 1); // Example term
    poly2 = insert(poly2, 4, 3, 1, 1);
    // Display the second polynomial POLY2(x, y, z)
    printf("POLY2(x, y, z) = ");
    display(poly2);
    // Add POLY1(x, y, z) and POLY2(x, y, z) and store the result in POLYSUM(x, y, z)
    polySum = add(poly1, poly2, polySum);
    // Display the sum POLYSUM(x, y, z)
    printf("\nPOLYSUM(x, y, z) = ");
    display(polySum);
    // Evaluate POLYSUM(x, y, z) for specific values
    int x = 1, y = 1, z = 1;
    int res = evaluate(polySum, x, y, z);
    printf("\nResult of POLYSUM(%d, %d, %d): %d\n", x, y, z, res);
    return 0;
}