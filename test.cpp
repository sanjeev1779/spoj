#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node * right;
    struct node* parent;
};


struct node* newnode(int data, struct node* par)
{
    struct node* temp= (struct node*)(malloc(sizeof(struct node)));
    temp->data= data;
    temp->left=NULL;
    temp->right=NULL;
    temp->parent= par;
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

struct node* bs(struct node* root, int node1)
{
    if(root==NULL) return NULL;
    if(root->data==node1) return root;
    if(root->data < node1) return bs(root->right,node1);
    if(root->data > node1) return bs(root->left,node1);
    return NULL;
}
void printpath(struct node* cur, int node2)
{
    if(cur==NULL) return;
     printf("%d ",cur->data);
    if(cur->data==node2) {
            printf("reached di\n\n\n\n");
        return;
    } // reached distination

    if(cur->data > node2) printpath(cur->left,node2);// left subtree

    if(cur->data < node2 && cur->parent==NULL) printpath(cur->right,node2);

    if(cur->data < node2 && cur->parent!=NULL && cur->parent->data >node2) printpath(cur->right,node2);
    if(cur->data < node2 && cur->parent!=NULL && cur->parent->data >node2)  printpath(cur->parent,node2);
    return ;
}
void path(struct node* root,int n1, int n2)
{
    struct node* node1= bs(root,n1);
    //printf("%d\n",node1->data);
    printpath(node1,n2);
    return;
}
int main()
{
    int node1,node2;
    struct node* root= newnode(2,NULL);
    root->left= newnode(-2,root);
    root->right= newnode(6,root);
    root->left->left= newnode(-4,root->left);
    root->left->right= newnode(0,root->left);
    root->right->left= newnode(4,root->right);
    root->right->right= newnode(8,root->right);
    inorder(root);
    printf("\n\n");
    scanf("%d %d",&node1,&node2);
    path(root,node1,node2);
       return 0;
}
