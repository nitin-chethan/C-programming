#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node{
    int data;
    struct node* next;
};

void insert(int x);
void print();
void reverse(struct node* p);

struct node * head;

int main()
{
    int n;
    head = NULL;
    insert(2);
    insert(4);
    insert(6);
    insert(5);
    print();
    struct node *p = head;
    reverse(p);
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


void reverse(struct node * p)
{
    if(p->next==NULL)
    {
        head = p;
        return;
    }
    reverse(p->next);
    p->next->next = p;
    p->next =NULL;
} 

