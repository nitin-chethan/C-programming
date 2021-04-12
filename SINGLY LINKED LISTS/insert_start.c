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

    int x,i,n;
    printf("ENter the number of elements.\n");
    scanf("%d",&n);

    printf("ENter the value of numbers\n");
    
    for(i=0;i<n;i++){
        scanf("%d",&x);
        head = insert(head,x);
        print(head);
    }

    return 0;
}

struct node* insert(struct node* head,int x)
{
    struct node* Z = (struct node*)malloc (sizeof(struct node));
    assert(Z!=NULL);

    Z ->data = x;
    Z ->next = head ;
    head = Z;
    return head;
}

void print(struct node* a)
{
    printf("The elements are: ");
    while( a != NULL )
    {
        printf("%d ",a->data);
        a = a->next;
    }
    printf("\n");
}