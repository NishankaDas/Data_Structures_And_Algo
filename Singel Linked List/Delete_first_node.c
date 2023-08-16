#Deleting first node
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
void del_at_beg(){
		node *temp = head->link; // creating a temporary pointer to store the address of the 
								// first node as if head is deleted then temp will store the address
		free(head); // deallocating head to delete first node
		head = temp; // updating head with temp (2nd node's address)
}
void see(node *x){
while(x!=NULL) //checking if the value of x (means the given value or increased value) is null or not
               // if it was x->link!=NULL the last node would not be check =ed and not be printed by the f(x)
{
    printf("%d\n",x->data); // printing dsata part
    x = x->link; // increamenting the link part of teh node
}
}
int main(){
	create(99);
	create(77);
	create(12);
	create(23);
	see(head);
	printf("\n");
	del_at_beg();
	del_at_beg();
	del_at_beg();
	see(head);
	return 0;
}
