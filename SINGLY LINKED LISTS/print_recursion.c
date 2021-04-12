#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node{
    int data;
    struct node* next;
};

struct node* head;

void insert(int x);
void print(struct node* p);


int main()
{
    int n;
    struct node * p;
    head = NULL;
    insert(2);
    insert(4);
    insert(6);
    insert(5);
    p= head;
    
    print(p);
}

void insert(int x)
{
    struct node* temp1 = (struct node*)malloc(sizeof(struct node));
    temp1 ->data = x;
    
    temp1-> next = head;
    head = temp1;
}

void print(struct node* p)
{
    if(p == NULL)
    {
        return;
    }
    printf("%d ",p ->data);
    print(p->next);
}