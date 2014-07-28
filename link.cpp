#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* newnode(int data)
{
        struct node* temp= (struct node*)(malloc(sizeof(struct node)));
        temp->data=data;
        temp->next=NULL;
        return temp;
}
void print(struct node* head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head= head->next;
    }
    return;
}
struct node* reverse_ll(struct node* head)
{
    struct node* prev,*cur,*temp;
    cur= head;
    prev= NULL;
    while(cur!=NULL)
    {
        temp= cur->next;
        cur->next= prev;
        prev=cur;
        cur=temp;
    }
    head=prev;
    //return head;
}
struct node* reverse_ite(struct node* head)
{
    if(head==NULL)return 0;
    reverse_ite(head->next);
    return head;
}
int main()
{
    int n;
    struct node* head=  newnode(1);
    head->next=  newnode(2);
    head->next->next= newnode(3);
    head->next->next->next= newnode(4);
    head->next->next->next->next= newnode(5);
    print(head);
    printf("\n");
    head=reverse_ll(head);
    print(head);
    printf("\n");
    swap_ll(head);

    printf("\n");
    return 0;
}
