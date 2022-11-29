//Binary Heap
#include<stdio.h>
void Insert(int A[],int n)
{
    int temp,i=n;
    temp=A[i];
    while(i>1 && temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}
void Delete(int A[],int n)
{
    int i,j,temp,x;
    x=A[1];
    A[1]=A[n];
    i=1,j=2*i;
    while(j<n-1)
    {
        if(A[j+1]>A[j])
         j=j+1;
        if(A[i]<A[j])
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*j;

        }
        else{
            break;
        }
    }
    A[n]=x;
}
int main()
{
    int A[]={0,1,2,3,4,5,6};
    int i;
    for(i=2;i<=6;i++)
    Insert(A,i);
    for(i=1;i<=6;i++)
    printf("%d ",A[i]);
    for(i=6;i>1;i--)
    Delete(A,i);
    printf("\n");
    for(i=1;i<=6;i++)
    printf("%d ",A[i]);

    return 0;
}
