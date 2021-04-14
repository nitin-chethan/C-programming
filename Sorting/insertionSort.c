#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void insertion_sort(int * A,int numElems);

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
    
    insertion_sort(A,numElems);

    for(int i=0;i<numElems;i++)
        printf("%d ",A[i]);

    return 0;    
    
}

void insertion_sort(int * A,int numElems)
{
    int i,j,curr;

    for(i=1;i<numElems;i++)
    {
        j=i-1;
        curr = A[i];
        
        while(j>=0 && A[j]>curr)
        {
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = curr;
    }
}
