#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node{
    int data;
    struct node* next;
};
int main()
{
    struct node* head;
    head = NULL;

    int n,x,i,pos,ele;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        insert(&head,x);
        print(head);
    }


    printf("\n\nEnter the position of the new element.\n");
    scanf("%d",&pos);

    if(pos>n+1)
    {
        printf("INVALID POSITION\n");
        return 0;
    }
    
    printf("Enter the data of the element\n");
    scanf("%d",&ele);
    insert_1(head,pos,ele);
    print(head);

    return 0;
}

void insert(struct node** A, int x)  //insert(&head,x);
{
    struct node* Z = (struct node*)malloc(sizeof(struct node));
    Z ->data = x;
    Z ->next = *A;
    *A = Z;
}

void print(struct node* head)
{
    printf("The elements are : ");
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head ->next;
    }
    printf("\n");
}


void insert_1 (struct node* head,int pos,int ele)
{   
    struct node* Z = (struct node*)malloc(sizeof(struct node));
    Z ->data = ele;

    for(int i=0;i<pos-2;i++)
    {
        head = head->next;
    }

    Z->next = head ->next;
    head ->next = Z;

}