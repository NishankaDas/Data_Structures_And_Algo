//Inserting node after given value
#include<stdio.h>
#include<stdlib.h>
typedef struct n_list{
	int data;
	struct n_list *link;
}node; //building a struct node type variable wich can hold a int type data and an address 
node *head = NULL; //creating a pointer to hold the address of the node
void make(int num)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = num; // Inserting value 
	newnode->link = NULL; // Making the link part NULL
	if(head == NULL)
	{
		head = newnode; //assigning head by newnode
	}
	else{
		node *temp; // using temp for holding the address of head
		temp = head;
		while(temp->link != NULL)
		{
			temp = temp->link; // Increamenting temp 
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
		printf("%d\n",see->data); // printing the data part of the nodes 
		see = see->link; // assigning head the link of the privious node's base address as link holds that
	}
	
}  
void insert(){
	watch(head); // before insering showing the alue 
	int x,y;
	printf("\nEnter after which you want to add node\t\t");
	scanf("%d",&x);
	printf("Enter the data you want to insert...\t\t");
	scanf("%d",&y);
	node *temp = head;
	node *newnode2 = (node *)malloc(sizeof(node));
	newnode2->data = y;
	while(temp->link!=NULL && temp->data !=x) /*The temp->link part will indicate if the list 
                                                has ended or not and the tamp->data part will 
                                                check the value needed */
	{
		temp = temp->link;
	}
	if(temp->data != x) //It means it dosen't exists in the list
	{
		printf("Value dosen't exixt in the list so the node is been added at last\n");
	}
	newnode2->link = temp->link; // Assigneng the newnode's link part with the next node's address
	temp->link = newnode2; //The previous node holdes the address of newly created node
}
int main(){
make(200);
make(590);
make(123);
insert();
watch(head);
return 0;
}
