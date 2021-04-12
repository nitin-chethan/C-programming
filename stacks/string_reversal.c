#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max_size 102

int A[max_size],top =-1;

void push(char x);
char pop();
void print();

int main()
{
    char string[100];
    printf("Enter the string u want to reverse  :)\n");
    scanf("%s",string);
    int l = strlen(string) ;

    for(int i=0;i<l;i++)
        push(string[i]);
    
    for(int i=0;i<l;i++)
        string[i] = pop();

    printf("%s",string);

    return 0;    
}

void push(char x)
{
    if(top==max_size-1)
    {
        printf("ERROR");
        return;
    }
    
    A[++top] = x;
}

char pop()
{
    char c;
    if(top == -1)
    {
        printf("satck empty");
        exit(0);
    }
    c = A[top]; 
    top--;

    return c;
}

void print()
{
    printf("The elemets are:");
    for(int i=0;i<=top;i++)
        printf("%c ",A[i]);
}

