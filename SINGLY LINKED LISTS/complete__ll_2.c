#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node{
    int data;
    struct node* next;
};

struct node * head;

void insert(int x);
void print();
void reverse();

int main()
{
    int n;
    head = NULL;
    insert(2);
    insert(4);
    insert(6);
    insert(5);
    print();
    reverse();
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

void reverse()
{
    struct node *next,*prev,*current;
    prev = NULL;
    current = head;
    
    while(current!=NULL)
    {
        next = current ->next;
        current-> next = prev;
        prev = current;  
        current = next;        
    } 
    head = prev;
}