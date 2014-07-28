#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node * right;
};


struct node* newnode(int data)
{
    struct node* temp= (struct node*)(malloc(sizeof(struct node)));
    temp->data= data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int maxd=-1;
void leftview(struct node* root,int level)
{
    if(root==NULL) return;
    if(maxd<level)
    {
        maxd= level;
        printf("%d ",root->data);
    }
    leftview(root->right,level+1);
    leftview(root->left,level+1);

    return;
}
int main()
{
    struct node* root= newnode(1);
    root->left= newnode(2);
    root->right= newnode(3);
    root->left->left= newnode(4);
    root->left->left->right= newnode(10);
    root->left->right= newnode(5);
    root->right->left= newnode(6);
    root->right->right= newnode(7);
    leftview(root,0);
    return 0;
}
