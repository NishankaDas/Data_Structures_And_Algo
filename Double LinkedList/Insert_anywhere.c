// Insert at any position
#include<stdio.h>
#include<stdlib.h>
typedef struct n{
    struct n *pre;
    int data;
    struct n *next;
}node;
node *head = NULL;
node *head2 = NULL;
node *newnode;
void make(int data)
{
     node *nnode = (node *)malloc(sizeof(node));
    nnode->pre = NULL;
    nnode->data= data;
    nnode->next = NULL;
    if(head==NULL)
    {
        head = nnode;
       
    }
    else{
        node *temp;
        temp = head;
        while(temp->next!=NULL)
        {
            
            temp = temp->next;
        }
        nnode->pre = temp;
        temp->next = nnode;
    }
    head2 = nnode;
    }
void add_after(int data)
{
    int f;
    
    node *temp = head;
    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->pre = NULL;
    
    while(temp->next!=NULL && data!=temp->data)
    {
        temp = temp->next;
    }
    
    if(data!=temp->data){
        printf("\nBhul data\n");
    }
    else if(data = temp->data )
    {
        printf("\nTo be added...\t");
        scanf("%d",&f);
        newnode->data = f;
        newnode->pre=temp;
        newnode->next = temp->next;
        if(temp->next)
            temp->next->pre = newnode;
        temp->next = newnode;
        head2 = newnode;
    }
}
void add_before(int data)
{
    int f;
    node *temp = head;
    node *p;
    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->pre = NULL;
    
    while(temp->next!=NULL && data!=temp->data)
    {
        p = temp;
        temp = temp->next;
    }
    
    if(data!=temp->data){
        printf("\nBhul data\n");
    }
    else if (data == temp->data){
        printf("\nTo be added...\t");
        scanf("%d",&f);
        newnode->data = f;
        newnode->pre = temp->pre;
        newnode->next = temp ;
        if(temp->pre)
        {
            temp->pre->next = newnode;
        }
        temp->pre = newnode;
        if(temp==head)
        {
            head = newnode;
        }
    }
}
void see1(node *see)
{
    printf("Data by Head ... \n");
    while(see!=NULL)
    {
        printf("%d\n",see->data);
        see = see->next;
    }
}
void see2(node *see)
{
    printf("Data by Head2 ... \n");
    while(see!=NULL)
    {
        printf("%d\n",see->data);
        see = see->pre;
    }
}
int main()
{
    make(99);
    make(88);
    make(77);
    see1(head);
    see2(head2);
    printf("\nEnter the node after which you want to add node \t");
    int g,m;
    scanf("%d",&g);
    add_after(g);
     printf("\nEnter the node before which you want to add node \t");
      scanf("%d",&m);
     add_before(m);
     see1(head);
     see2(head2);
    
}   
