//Inserting node in Double Linked List at last
#include<stdio.h>
#include<stdlib.h>
typedef struct n{
    struct n *pre;
    int data;
    struct n *next;
}node;
node *head = NULL;
node *head2 = NULL;
void insert(int value)
{ 
   
    node *nnode = (node *)malloc(sizeof(node));
    nnode->pre = NULL;
    nnode->data= value;
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
    see1(head);
    see2(head2);
    printf("Enter 1 to insert again\nIt will be added at end \t");
    scanf("%d",&j);
    if(j==1)
    {
        printf("\nEnter data ... ");
        int q;
        scanf("%d",&q);
        insert(q);
       
        see1(head);
        see2(head2);
    }
}   
