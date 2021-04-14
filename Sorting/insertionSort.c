#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void insertion_sort(int * A,int numElems,int fun(const int a, const int b));
int inc(int a, int b);
int dec(int a, int b);

int main()
{
    int numElems =5;
    
    //printf("Enter the no of elements.\n");
    //scanf("%d",&numElems);

    //int* A = (int *)malloc(sizeof(int)*numElems); 
    //assert(A!=NULL);

    //printf("Enter the elements\n");
    //for(int i=0;i<numElems;i++)
    //    scanf("%d",A[i]);
    int A[5] = {4,3,7,9,1};

    insertion_sort(A,numElems,inc);

    for(int i=0;i<numElems;i++)
        printf("%d ",A[i]);

    printf("\n");
    insertion_sort(A,numElems,dec);

    for(int i=0;i<numElems;i++)
        printf("%d ",A[i]);


    return 0;    
    
}

int inc(int a, int b)
{
    return(a<b);
}


int dec(int a, int b)
{
    return(a>b);
}


void insertion_sort(int * A,int numElems,int fun(const int a,const int b))
{
    int i,j,curr;

    for(i=1;i<numElems;i++)
    {
        j=i-1;
        curr = A[i];
        
        while(j>=0 && fun(curr,A[j]))
        {
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = curr;
    }
}
