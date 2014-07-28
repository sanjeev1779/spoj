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

void inorder(struct node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
    return;
}

struct node* mirror(struct node*root)
{
    if(root==NULL)return NULL;

    mirror(root->left);
    mirror(root->right);

    struct node* temp;
    temp=root->left;
    root->left=root->right;
    root->right=temp;
    return NULL;
}
int main()
{
    struct node* root= newnode(1);
    root->left= newnode(2);
    root->right= newnode(3);
    root->left->left= newnode(4);
    root->left->right= newnode(5);
    root->right->left= newnode(6);
    root->right->right= newnode(7);
    inorder(root);
    //levelorder(root);
    printf("\n");
    mirror(root);
    inorder(root);
    return 0;
}
