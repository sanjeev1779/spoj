#include<stdio.h>
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
int ans=0;//not found
int check_sum(struct node* head,int sum)
{
    if(head==NULL) return;
    sum= sum- head->data;
    printf("%d %d\n",head->data,sum);
    if(sum==0) { printf("%d\n",head->data);ans=1; return ans; }
    //if(sum<0) return 0;
    if(head->left)
        ans= ans || check_sum(head->left,sum);
    if(head->right)
        ans = ans || check_sum(head->right,sum);
    return ans;
}
int main()
{
    int sum;
    struct node* root= newnode(1);
    root->left= newnode(2);
    root->right= newnode(3);
    root->left->left= newnode(4);
    root->left->right= newnode(5);
    root->right->left= newnode(6);
    root->right->right= newnode(7);
    printf("Enter the sum\n");
    scanf("%d",&sum);
    struct temp* temp=root;
    check_sum(temp,sum);
    return 0;
}
