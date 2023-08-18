// Insert at first in doubly linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct n{
    struct n *pre;
    int data;
    struct n *next;
}node;
node *head = NULL;
node *head2 = NULL;
void make(int data)
{
    node *temp;
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    if(head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
        head2 = head;
    }
    else{
        temp = head;
        while(temp->pre!=NULL)
        {
            temp = temp->pre;
        }
        temp->pre = newnode;
        newnode->next = temp;
        newnode->pre = NULL;
       
    }
     head = newnode;
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
    make(22);
    see1(head);
    see2(head2);
}   
