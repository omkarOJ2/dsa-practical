#include<stdio.h>
void towerH(int n,char s,char d,char a);

int main()
{
    int n;
    char A='A',B='B',C='C'; //A=source ,B=destination C=helper
    printf("Enter the heigth of tower :");
    scanf("%d",&n);
    towerH(n,A,B,C);
}
void towerH(int n,char s,char d,char a)
{
    if(n==1)
    {
        printf("\nmove %d from %c to %c",n,s,d);
        return;
    }
    towerH(n-1,s,a,d);
     printf("\nmove %d from %c to %c",n,s,d);
     towerH(n-1,a,d,s);
}