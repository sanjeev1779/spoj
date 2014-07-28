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
int max_level=0;
void right_view(struct node* head,int level)
{
    if(head==NULL) return;

    if(max_level<level)
    {
        max_level= level;
        printf("%d ",head->data);
    }
    right_view(head->left,level+1);
    right_view(head->right,level+1);
    return;
}
void print_leaf(struct node* root)
{
    if(root==NULL)return;
     print_leaf(root->left);
    if(root->left==NULL && root->right==NULL) printf("%d\n",root->data);

    print_leaf(root->right);

    return;
}

int main()
{
    struct node* root= newnode(1);
    root->left= newnode(2);
    root->right= newnode(3);
    root->left->left= newnode(4);
    root->left->left->left= newnode(9);
    root->left->left->right= newnode(10);

     root->left->right= newnode(5);
     root->left->right->left= newnode(11);
     root->left->right->right= newnode(12);

    root->right->left= newnode(6);
    root->right->right= newnode(7);
    root->right->right->left= newnode(8);
    struct node* head= root;
    int max_level=0;
    right_view(head,1);
    head=root;
    print_leaf(head);
    return 0;
}
