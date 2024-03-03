/*Develop a menu driven Program in C for the following operations on Binary Search Tree
(BST) of Integers .
a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
b. Traverse the BST in Inorder, Preorder and Post Order
c. Search the BST for a given element (KEY) and report the appropriate message
d. Exit*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int info;
    struct node *rnode,*lnode;
};
typedef struct node* Node;

Node inset(Node root,int elem)
{
    Node temp=(Node)malloc(sizeof(struct node));
    temp->info=elem;
    temp->lnode=NULL;temp->rnode=NULL;
    Node cur=root,prev=NULL;
    if(root==NULL)
        return temp;
    
    while(cur!=NULL)
    {
        prev=cur;
        if(cur->info==elem)
        {
            printf("\n no duplicate item is allowed \n");
            free(temp);
            return root;
        }
            cur=(elem<cur->info)?cur->lnode:cur->rnode;
    }
    if(elem>prev->info)
        prev->rnode=temp;
    else 
        prev->lnode=temp;
    return root;
}
void preorder(Node root)
{
    if(root!=NULL){
    printf("%d",root->info);
    preorder(root->lnode);
    preorder(root->rnode);
    }
}

void postorder(Node root)
{
    if(root!=NULL){
    postorder(root->lnode);
    postorder(root->rnode);
    printf("%d",root->info);
    }
}
void inorder(Node root)
{
    if(root!=NULL){
    inorder(root->lnode);
    printf("%d",root->info);
    inorder(root->rnode);
    }
}

void searchB(Node root,int elem)
{
    Node cur=root;
    if(cur!=NULL)
    {
        if(elem>cur->info)
            searchB(cur->rnode,elem);
        else if(elem<cur->info)
            searchB(cur->lnode,elem);
        else
            printf("\n %d is found in tree",elem);
    }
    else
        printf("\n %d is not found in tree",elem);
}
int main()
{
    Node root = NULL;
    int ch, elem, i, n;
    printf("Create a BST of N Integers \n");
    printf("\nEnter the number N : ");
    scanf("%d", &n);
    printf("\nEnter %d numbers\n", n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &elem);
        root = inset(root,elem);
    }
    for(;;)
    {
        printf("===================");
        printf("\n1.Inorder traversal\n2.Preorder traversal");
        printf("\n3.Postorder traversal\n4.Search\n5.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if(root ==NULL)
                        printf("\nTree is Empty\n");
                    else
                    {
                        printf("\nInorder Traversal is :\n");
                        inorder(root);
                        printf("\n");
                    }
                    break;
            case 2: if(root ==NULL)
                        printf("\nTree is Empty\n");
                    else
                    {
                        printf("\nPreorder Traversal is :\n");
                        preorder(root);
                        printf("\n");
                    }
                    break;
            case 3: if(root ==NULL)
                        printf("\nTree is Empty\n");
                    else
                    {
                        printf("\nPostorder Traversal is :\n");
                        postorder(root);
                        printf("\n");
                    }
                break;
            case 4: printf("\nEnter the element to be searched : ");
                    scanf("%d", &elem);
                    searchB(root, elem);
                    break;
            case 5: exit(0);
            default: printf("Wrong choice\n");
                        break;
         }
    }
return 0;
}