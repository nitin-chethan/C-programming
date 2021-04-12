#include"ssl.h"
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

void CreateEmptyNode(PtrToNode* P,int x)
{
    PtrToNode PLocal = MakeNode(x);
    *P = PLocal;
}

PtrToNode MakeNode(int x)
{
    PtrToNode P = (PtrToNode) malloc (sizeof(list));
    assert(P!=NULL);
    P ->element = x;
    P ->Next = NULL;
    return P;
}

void InsertElement(PtrToNode P,int x)   //value of P doesnt change as it is an local variable to that function..
{
    PtrToNode PNew = MakeNode(x);

    while(P->Next !=NULL){
        P = P->Next;
    }
    P->Next = PNew;
}

void InsertElement_2(PtrToNode* P,int x)
{
    PtrToNode PNew = MakeNode(x);
    PtrToNode T = *P;
    *P = PNew;
    (*P) ->Next = T;    
}

void DeleteNode(PtrToNode P)
{
    while(P->Next !=NULL){
        P = P->Next;
    }
    PtrToNode T = P;
    P = NULL;
    free(T);
}

void DeleteNode_2(PtrToNode P)
{
    PtrToNode T = P;
    P = P->Next;
    free(T);
}

void deletelist(PtrToNode P)
{
    free(P);
}

void PrintList(PtrToNode P)
{
    while( P!=NULL )
    {
        printf("%d",P->element);
        P = P->Next;
    }
}