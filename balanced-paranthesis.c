#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#define max_size 1000

char B[max_size];
top =-1;

int main()
{
    char A[max_size];
    int n;

    printf("Enter the string.\n");
    gets(A);
    n  = strlen(A);
    for(int i=0;i<n;i++)
    {
        if(A[i] == '(')
            push(1);
        if(A[i] ==')')
            pop();
    }
    if(top == -1)
        printf("BALANCED PARENTHESIS");
    else
        printf("UNBALANCED");
}

void push(int x)
{
    B[++top] = x;
}

void pop()
{
    top--;
    if(top <-1)
    {
        printf("INVALID");
        exit(0);
    }
}

