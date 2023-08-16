#include<stdio.h>
#include<stdlib.h>
typedef struct n_list{
    int data;
    struct n_list *link;
}node;
node *head = NULL;
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
    while(see!=NULL)
    {
        printf("%d\n",see->data);
        see = see->link;
    }

}  //Same as previous programs
void rev()
{
    node *temp=head; //assigning temp by head
    node *hold = temp->link; // hold will hold the next node's address
    head->link = NULL; //making the first node's link part null
    while(hold!=NULL)
    {
        temp=hold; // temp increments one as head is one node after temp
        hold=hold->link; // hold changes its value by the link part of the previous node (for 1st time it becomes the address of third)
        /*In this portion the hold will firstly hold the 2nd node's address then temp is assigned the address of hold and hold is incremented 
        by one node now temp holdes the address of node 2 and hold holds the address of number 3 and the 1st node's link part becomes NULL 
        by the previous code the link part of the temp is assigned to head which holds the 1st node's address ... this thing contines up to 
        when the hold part becomes NULL means the end of the list*/
        temp->link=head; // The link of the next node brccomes the first's address
        head=temp; // incrementing head
    }
    printf("\n\n");
    watch(head); // 
}
int main()
{
    int x=0,y,z;
    printf("How many data you want to insert\t");
    scanf("%d",&y);
    while(x<y)
    {
        scanf("%d",&z);
        make(z); // creating nodes
        y--;
    }
    printf("\n\nEntered Data is \n\n");
    watch(head);
    rev();
}
