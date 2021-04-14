#include<stdio.h>

void bubbleSort(int* A,int numElems);

int main()
{
    int A[] = {3,4,2,1,6};
    int numElems = 5;

    bubbleSort(A,numElems);

    for(int i=0;i<numElems;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;    
}

void bubbleSort(int A[],int numElems)
{
    int count = -1;
    int temp;


    for(int i=0;i<numElems;i++)
    {
        if(count == 0 )
            return;
        count =0;
        for(int j=0;j<numElems-i-1;j++)
        {

            if(A[j]>A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                count ++;
            }

        }
    }
}
