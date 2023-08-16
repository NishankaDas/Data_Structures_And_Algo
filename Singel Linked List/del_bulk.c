#include<stdio.h>
#include<stdlib.h>
typedef struct n{
    int data;
    struct n *link;
}node;
node *head = NULL;
void make(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->link = NULL;
    if(head==NULL)
    {
        head = newnode;
    }
    else{
        node *temp;
        temp = head;
        while(temp->link!=NULL)
        {
            temp = temp->link;
        }
        temp->link = newnode;
    }
}
void see(node *s)
{
    while(s!=NULL)
    {
        printf("%d\t",s->data);
        s = s->link;
    }
}
void del()
{
    printf("\nUp to which value do you want to delete in bulk\t");
    int x;
    scanf("%d",&x);
    node *temp , *prev;
    temp = prev = head;
    int flag =0;
   
    while(temp->link!=NULL && temp->data!=x)
    {
        prev = temp;
        temp = temp->link;      
    }
   
   if(temp->data!=x)
    {
        printf("Not in the list \nPlease enter right value");
        del();
        flag =1;
    }
   else if(flag==0){
     while(temp->link!=NULL && temp->data!=x)
    {
        prev = temp;
        temp = temp->link;
       
        free(prev);    
    }
     head = temp;
     see(head);
     }
    else if(head==NULL)
    {
        printf("Nothing is here ");
    }
   
}
int main()
{
    int j;
    for(j=0;j<10;j++)
    {
        make(j*12);
    }
    see(head);
    del();
}