//Inserting node before given value
#include<stdio.h>
#include<stdlib.h>
typedef struct n_list{
	int data;
	struct n_list *link;
}node;//building a struct node type variable wich can hold a int type data and an address
node *head = NULL; //creating a pointer to hold the address of the node
void make(int num)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = num; // Inserting value
	newnode->link = NULL; // Making the link part NULL
	if(head == NULL)
	{
		head = newnode;
	}
	else{
		node *temp; // using temp for holding the address of head
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
	while(see!=NULL) /* checks if the adress stored in head is null or not 
					it is not writen "see->link!=NULL" because it will prevent printing the 
				    first node created as it's link part is NULL , but if it is written 
				   	"see!=NULL" it will take to the point when the Head was created and assigned
				   	as NULL*/
	{
		printf("%d\n",see->data);
		see = see->link;
	}
	
}
void insert(){
	watch(head);
	int x,y;
	printf("\nEnter before which you want to add node\t\t");
	scanf("%d",&x);
	printf("Enter the data you want to insert...\t\t");
	scanf("%d",&y);
	node *temp,*prev;
	temp = prev = head;
	node *newnode2 = (node *)malloc(sizeof(node));
	newnode2->data = y;
	while(temp->link!=NULL && temp->data !=x)
	{	
		prev=temp; // using prev pointer to store previous address
		temp = temp->link;
	}
	if(temp==head) //It is needed if the first number is given
	{
		printf("Value is at the first\n");
		newnode2->link = head;
		head = newnode2;
	}
	else{
		newnode2->link = prev->link; //Node holding address of the temp
		prev->link= newnode2; // The previous link part is updated with newnode2's value
	}
}
int main(){
make(200);
make(590);
make(123);
insert();
watch(head);
return 0;
}
