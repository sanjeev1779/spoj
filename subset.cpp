#include<stdio.h>


struct node
{
    int data;
    struct node* left,right;
};

struct node* newnode(int data)
{
        struct node* new_node= (struct node*)malloc(sizeof(struct node));
        new_node->data=data;
        new_node->left= NULL;
        new_node->right= NULL;
        return new_node;
}
int path(struct node* node,int arr[],int pathlen)
{
    arr[pathlen++]=node->data;
    if(node->left==NULL && node->right==NULL)// leaf node
    {

    }
     path(node->left,arr,pathlen);
     path(node->right,arr,pathlen);
}
int main()
{
    struct node* root= newnode(1);
    root->left=2;
    root->right=3;
    root->left->left=4;
    root->left->right=4;
    root->right->left=3;
    root->right->right=3;
    struct node* head= root;
    path(root);
    return 0;
}
