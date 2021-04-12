#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node{
    int data;
    struct node* next;
};

void insert(int x);
void print();
void delete(int n);


struct node* head;

int main()
{
    int n;
    head = NULL;
    insert(2);
    insert(4);
    insert(6);
    insert(5);
    print();
    printf("Enter the position\n");
    scanf("%d",&n);
    delete(n);
    print();
}

void insert(int x)
{
    struct node* temp1 = (struct node*)malloc(sizeof(struct node));
    temp1 ->data = x;
    
    temp1-> next = head;
    head = temp1;
}

void print()
{
    struct node* p;
    p = head;
    printf("The elements are : ");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

void delete(int n)
{
    struct node* temp1 = head;
    if(n==1)
    {
        struct node* del = head;
        head = head ->next;
        free(del);
    }
    else
    {   struct node* temp2;
        for(int i=0;i<n-2;i++)
            temp1 = temp1->next;
        temp2 = temp1->next;
        temp1->next = temp1->next->next; 
        free(temp2);
    }  
}