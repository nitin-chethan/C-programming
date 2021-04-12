#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


struct node{
    int data;
    struct node* right;
    struct node* left;
};

int depth =0;

struct node* insert(struct node *root,int x);
struct node* makeNode(int x);
int min(struct node* root);
int max(struct node* root);
bool search(struct node* root,int ele);
//struct node* bst_sort(struct node* root);

void finddepth(struct node* root,struct node* P);
bool isbst(struct node* root);
int height(struct node* root);
void bst_sort(struct node* root);
void inRange(struct node* root,int k1,int k2);


struct node* insert(struct node* root,int x)
{
    if(root == NULL){
        root = makeNode(x);
        return root;
    }

    if(x <= root->data)
        root->left = insert(root->left,x);

    else
        root->right = insert(root->right,x);
}

struct node* makeNode(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp ->data = x;
    temp ->left =NULL;
    temp ->right =NULL;
    return temp; 
}

int min(struct node* root)
{
    if(root == NULL)
        printf("Error: The given tree is empty.\n");
    else if(root ->left == NULL)
        return root->data;
    else 
        return min(root->left);
}

int max(struct node* root)
{
    if(root == NULL)
        printf("Error: The given tree is empty.\n");
    else if(root ->right == NULL)
        return root->data;
    else 
        return min(root->right);
}

bool search(struct node* root,int ele)
{
    if(root == NULL)
        return false;
    else if(root->data == ele)  
        return true;
    else if(ele < root->data)
        return search(root->left,ele);
    else 
        return search(root->right,ele);
    
}

/*struct node* bst_sort(struct node* root)
{
    root->left = bst_sort(root->left);
    if(root->left->left ==NULL && root->left->right == NULL)
    {
        printf("%d %d ",root->left->data,root->data);
        return root;
    }
    root->right = bst_sort(root->right);
}*/

void bst_sort(struct node* root)
{
    if(root->left ==NULL && root->right == NULL){
        printf("%d ",root->data);
        return;
    }
    
    if(root->left!=NULL){
    bst_sort(root->left);
    }
    printf("%d ",root->data);
    if(root->right!=NULL)
        bst_sort(root->right);

    return;
}

bool isbst(struct node* root)
{
    if(root->right == NULL && root ->left ==NULL)
    {
        return true;
    }
    else if(root->right == NULL)
        isbst(root->left);
    else if(root->left == NULL)
        isbst(root->right);

    else if(root->left->data < root->data && root->right->data >root->data)
    {
        isbst(root->left);
        isbst(root->right);
    }
    else 
        return false;

}

void finddepth(struct node* root,struct node* P)
{
    
    if(root == NULL)
        printf("ERROR : Tree is empty");
    if(root->data == P->data)
        return;
    else if(P->data > root->data){
        finddepth(root->right,P);
        depth++;
    }
    else if(P->data < root->data){
        finddepth(root->left,P);
        depth++;
    }
    
}

int height(struct node* root)
{
    
    int max;

    if(root == NULL)
        return -1;

    int leftHeight = height(root ->left);
    int rightHeight = height(root ->right);
    return max = leftHeight >= rightHeight ? leftHeight+1 :rightHeight+1;  
}

void inRange(struct node* root,int k1,int k2)
{
    if(root->left ==NULL && root->right == NULL)
    {
        if(k1<=root->data && root->data<=k2)
        {
            printf("%d ",root->data);
            return;
        }
        else
            return;
    }
    
    if(root->left!=NULL){
    inRange(root->left,k1,k2);
    }
    if(k1<=root->data && root->data<=k2){
        printf("%d ",root->data);}
    if(root->right!=NULL){
        inRange(root->right,k1,k2);}

    return;
}


int main()
{
    int n,least;
    int hei;
    struct node* root = NULL;
    root = insert(root,10);
    root = insert(root,5);
    root = insert(root,12);
    root = insert(root,15);
    root = insert(root,11);
    root = insert(root,1);
 

    printf("\n\n\nEnter the elememt to be found.\n");
    scanf("%d",&n);
    if(search(root,n) == true)
        printf("found\n\n");
    else 
        printf("not found\n\n");

    least = min(root);
    printf("%d\n",least);

    hei = height (root); 
    printf("Height of tree is %d\n",hei);

    if(isbst(root)==true)
        printf("valid\n");

    else 
        printf("not  valid\n");
    finddepth(root,root->right->left);
    printf("The depth of the binary tree is %d\n",depth);

    bst_sort(root);
    printf("\n");
    inRange(root,1,18);

    return 0;
}

