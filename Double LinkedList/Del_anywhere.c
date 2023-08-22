//Delete any node
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
void del(int de){
    node *temp = head;
    node *pree=NULL;
    while(temp->next!=NULL && de!=temp->data)
    {
        pree = temp;
        temp = temp->next;
    }
    if(pree!=NULL && de == temp->data)
    {
        if(temp->next)
        {
            temp->next->pre  = temp->pre;
            temp->pre->next = temp->next;
            free(temp);
        }
        else{
            pree->next = NULL;
            head2 = pree;
            free(temp);
        }
    }
    else if(pree == NULL && de == temp->data){
        if(temp->next){

            temp->next->pre = NULL;
            head = temp->next;
            free(temp);
        }
        else{
            printf("No Node availabel");
            if(temp)
            {
                free(temp);
            }
        }
    }
    else{
        printf("Nei nei osob kichu nei\n R akbar dekhai");
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
    while(1){
        printf("Enter which data you want to delete \t");
        scanf("%d",&j);
        del(j);
        see1(head);
        see2(head2);
    }
}   
