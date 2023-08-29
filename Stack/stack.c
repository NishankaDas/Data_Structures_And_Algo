#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *link;
}node; //building a struct node type variable wich can hold a int type data and an address 
struct node *head = NULL; 

void input(int value)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node)); // creating node
	if(head==NULL) //it means it is the first node which is created
	{
		newnode->data= value; // assigning value top the node's data part
		newnode->link = NULL; // as in this case the link of 1st node is not needed then it's NULL
		head = newnode; // assigning head the address of the node
	}
	else{ // for n th node n>1
		newnode->link=head; /* assigning the link of the new node with the
							            address of previous node saved in head */
		newnode->data = value; // assigining value to the node
		head = newnode; // updating the value of head with recently created node's address
	}	
}
void del()
{
    node *temp=head;
    
    if(head == NULL)
    {
        printf("Kichu Lai");
    }
    else{
        head = temp->link;
        free(temp);
    }

}
void see(node *head)
{
    if(head==NULL)
    {
        printf("Kichu Lai");
    }
    else
        printf("\nThe Top is %d\n",head->data);
}
int main()
{
    while(1)
    {
        printf("\nEnter 1 to insert, 2 to See the Top , 3 to del , Other to Exit\t");
        int x;
        scanf("%d",&x);
        if(x==1)
        {
            int y;
            printf("\nInsert Data...\t");
            scanf("%d",&y);
            input(y);
        }
        else if(x==2)
        {
            see(head);
        }
        else if(x==3)
        {
            del();
        }
        else{
            printf("Bhuter Raja Dilo Bor 1,2,3 \n 4,5,6 osob kichu nei Ok bye");
            break;
        }
    }
}
