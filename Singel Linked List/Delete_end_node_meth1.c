//Deleting End Node by Method one (Not using two local pointers while deleting)
#include<stdio.h>
#include<stdlib.h>
typedef struct a {
    int data;
    struct a *link;
}node;  //building a struct node type variable wich can hold a int type data and an address
node *head = NULL; //creating a pointer to hold the address of the node
void create(int num)
{
    node *newnode = (node*)malloc(sizeof(node)); //creating a node
    newnode->data = num; // updating value in the data part
    newnode->link = NULL; // setting the link as null
    if(head == NULL) // checking if head is NULL
    {
     head = newnode; // giving the address of the newly created node
    }
    else{
        node *temp; // creating a node type pointer
        temp= head; // assigning temp the value of head
        while(temp->link !=NULL) //if temp->link is not null then there is more node in list
        {
            temp = temp->link; // getting the next from the present node and assigning the value of temp as it
        }
        temp->link = newnode; // if the link is null then its not connectec to the newly created node , si cinnecting the node
    }
}
void see(node *x){
while(x!=NULL) //checking if the value of x (means the given value or increased value) is null or not
               // if it was x->link!=NULL the last node would not be check =ed and not be printed by the f(x)
{
    printf("%d\n",x->data); // printing dsata part
    x = x->link; // increamenting the link part of teh node
}
}
void del_at_end(){
	if(head->link==NULL) //checking if the node to be deleted is the first node or not
	{
		free(head); // if first node thenn delete
		head = NULL;
	}
	else{
		node* tmp=head; // too keep the address of the first node
		while(tmp->link->link!=NULL) /*Suppose there are 3 nodes and it is checking first time
										then the temp is pointing the first node and the temp link 
										is holding address of the second node , here we are checking if the 
										second node's link part is NULL or not . As the last node 
										of the list will have NULL at link part it will identify the 
										previous node of the last node*/
		{
			tmp=tmp->link;  // updating the temp by one node
		}
		free(tmp->link); // deallocating the node 
		tmp->link=NULL; // declearing the node as NULL
	}
    }	
int main(){
	create(99);
	create(77);
	create(56);
	see(head);
	del_at_end();
	create(36);
	create(16);
	create(78);
	create(30);
	printf("\n");
	see(head);
	printf("\n");
	printf("\n");
	del_at_end();
	del_at_end();
	del_at_end();
	del_at_end();
	see(head);
return 0;
}
