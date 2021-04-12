#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node{
    int data;
    struct node* next;
};

struct node* head;

void insert(int x, int n);
void print();

int main()
{
    head = NULL;
    insert(2,1);
    insert(3,2);
    insert(4,1);
    insert(5,2);
    print();

}

void insert(int x, int n)
{
    struct node* new1 = (struct node *)malloc(sizeof(struct node));
    new1 ->data = x;
    new1 ->next = NULL;
    if(n == 1){
        new1 ->next = head;
        head = new1;
    }
    else{
        struct node* new2 = head;
        
        for(int i=0;i<n-2;i++){
        new2 = new2 ->next;
        }
        new1->next = new2 ->next;
        new2 -> next = new1;
    }
}

void print()
{
    struct node* p = head;
    while(p != NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}