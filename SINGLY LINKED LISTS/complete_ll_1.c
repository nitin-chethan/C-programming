#include<stdio.h>
#include <assert.h>
#include<stdlib.h>


struct node{
    int data;
    struct node * next;
};

struct node* head;

void insert(int x,int n);
void insert_2(int x);
void rev_print(struct node *p);
void print(struct node *p);
void delete(int n);

int main()
{
    head = NULL;
    insert(2,1);
    insert_2(5);
    insert_2(4);
    insert(1,2);
    insert(7,3);
    delete(4);

    struct node * p=head;

    print(p);
    printf("\n");
    p = head;
    rev_print(p);
    printf("\n");

    return 0;
}


void insert_2(int x)
{
    struct node* new  = (struct node*)malloc(sizeof(struct node));
    new->data =x;
    new->next = head;
    head = new;
}


void insert(int x,int n)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new ->data = x;
    if(n==1)
    {
        new -> next = head;
        head = new;
    }    
    else
    {
        struct node* p = head;
        for(int i=0;i<n-2;i++)
            p = p->next;
        new->next = p->next;
        p -> next = new;
    } 
}

void print(struct node* p)
{
    if(p==NULL)
        return;
    
    printf("%d ",p->data);
    print(p->next);
}

void rev_print(struct node *p)
{
    if (p == NULL)
    {
        return;
    }
    rev_print(p->next);
    printf("%d ",p->data);
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