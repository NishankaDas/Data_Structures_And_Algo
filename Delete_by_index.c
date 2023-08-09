//Deleting node by index
#include<stdio.h>
#include<stdlib.h>
typedef struct n{
int data;
struct n *link;
}node;
node *head = NULL;
int count=0;
void make(int num)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = num;
    newnode->link = NULL;
    if(head == NULL)
    {
        head = newnode;
    }
    else{
        node *temp;
        temp = head;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newnode;
    }
}
void watch(node *see)
{
    count =0;
    while(see!=NULL)
    {
        printf("%d is the data indexed by %d\n",see->data,count);
        see = see->link;
        count++;
    }
}
void del()
{
node *temp ,*prev;
temp = prev = head;
watch(head);
int x,pos=0;
printf("Enter the Index number\t");
scanf("%d",&x);
while(temp->link!=NULL && pos !=x)
    {  
prev=temp;
temp = temp->link;
pos++;
    }
    if(pos!=x)
    {
    printf("\nEnter valid IndeX\n");
    }
    else if(pos==0)
    {
    head = temp->link;
    free(temp);
    watch(head);
    }
    else{
    prev->link = temp->link;
    free(temp);
    watch(head);
    }
}
int main(){
make(4563);
make(4123);
make(8756);
make(9123);
make(8756);
make(2123);
make(5756);
make(4123);
make(7756);
del();
}
