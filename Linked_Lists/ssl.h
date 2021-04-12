#ifndef __SSL_H
#define __SSL_H


typedef struct node* PtrToNode;

typedef struct node{
    int element;
    PtrToNode Next;
}list;

PtrToNode MakeNode(int x);
void CreateEmptyNode(PtrToNode* P,int x);

void InsertElement(PtrToNode P,int x); //To the end of List.
void InsertElement_2(PtrToNode* P,int x);//To the start of the List.
void DeleteNode(PtrToNode P);
void DeleteNode_2(PtrToNode P);

void deletelist(PtrToNode P);


#endif