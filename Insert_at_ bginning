//Inserting node at first
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
}; //building a struct node type variable wich can hold a int type data and an address 
struct node *head = NULL; //creating a pointer to hold the address of the node
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
void display(){
	struct node *temp = head; /* here we are initilazing temp with head so it will not lose the base address 
							            	stored in head , it will loose the base address of the head if we  increment the 
								             link part in head. therefore we are using this "temp" variable*/
	while(temp!=NULL) /* checks if the adress stored in head is null or not 
					        	it is not writen "temp->link!=NULL" because it will prevent printing the 
						         first node created as it's link part is NULL , but if it is written 
					        	"temp!=NULL" it will take to the point when the Head was created and assigned
					         	as NULL*/
	{
		printf("%d\n",temp->data); // printing the data part of the nodes 
		temp = temp->link; // assigning head the link of the privious node's base address as link holds that
	}
}
int main()
{
	input(9); 
	input(11);
	input(145);
	display();
	printf("End of 1st command\n"); // to check if the base address is lost or not 
	input(10);
	input(44);
	display();
	return 0;
}
