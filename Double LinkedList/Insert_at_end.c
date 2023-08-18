//Inserting node in Double Linked List at last
#include<stdio.h>
#include<stdlib.h>
typedef struct n{
    struct n *pre;
    int data;
    struct n *next;
}node;
node *head = NULL;
node *head2;
void insert(int data)
{
    node *nnode = (node *)malloc(sizeof(node));
    nnode->data = data;
    node* temp1;
   
    nnode->next = NULL;
    if(head == NULL)
    {
        nnode->pre = NULL;
        head = nnode;
       
    }
    else{
        temp1 = head;
        while(temp1->next!=NULL){
            temp1 = temp1->next;
           
        }
        nnode->pre = temp1;
        temp1->next = nnode;

    }
    head2 = nnode;
}
void seen(node *r)
{
    printf("By Head display...\n");
    while(r!=NULL)
    {
        printf("%d\n",r->data);
        r = r->next;
    }
}
void seer(node *r)
{
    printf("By Head2 display...\n");
    while(r!=NULL)
    {
        printf("%d\n",r->data);
        r = r->pre;
    }
}
int main()
{
    int i,j=0;
    printf("Enter how many node you want\t");
    scanf("%d",&i);
    while(j<i)
    {
        printf("Enter data ... ");
        int x;
        scanf("%d",&x);
        insert(x);
        j++;
    }
    seen(head);
    seer(head2);
    while(1)
    {
        printf("Enter 1 to enter data and any integar to exit\t");
        int p,m;
        scanf("%d",&p);
       
        if(p==1)
        {
            printf("Enter data...\t");
            scanf("%d",&m);
            insert(m);
            seen(head);
            seer(head2);
        }
        else
        { 
            break;
        }
           
    }
}   
