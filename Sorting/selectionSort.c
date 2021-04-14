#include<stdio.h>


void selectionSort(int A[],int numElems);
int main()
{
    int A[] = {6,5,1,8,4};
    int numElems = sizeof(A)/sizeof(A[0]);
    printf("The elements in unsorted order are : ");
    for(int i=0;i<numElems;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    selectionSort(A,numElems);

    printf("The elements in sorted order are : ");
    for(int i=0;i<numElems;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}

void selectionSort(int A[],int numElems)
{
    
    int min,temp,pos;
    for(int j=0;j<numElems-1;j++)
    {
        min=A[j];
        for(int i=j;i<numElems;i++)
            min = min < A[i] ? min : A[i];
        
        for(int i=j;i<numElems;i++)
        {
            if(min == A[i]){
                pos = i;
                break;
            }
        }   

        temp = A[j];
        A[j] = min;
        A[pos] = temp;
    }
}
