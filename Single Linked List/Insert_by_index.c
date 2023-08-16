//Insert at any point using Index
#include<stdio.h>
#include<stdlib.h>
typedef struct n_list{
	int data;
	struct n_list *link;
}node;
node *head = NULL;
int count=0;
void make(int num)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = num; //Updating data with given number
	newnode->link = NULL; // Making link NULL
	if(head == NULL)
	{
		head = newnode;
	}
	else{
		node *temp;
		temp = head; // using temp for holding the address of head
		while(temp->link != NULL)
		{
			temp = temp->link; //Updating temp 
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
		count++; //using cout for indexing
	}
	
}
void sel(){ //selecting the process
	printf("If you want to insert after your desired position Enter 1\nif you want before Enter 2\t");
	int x;
	scanf("%d",&x);
	if(x==1)
	{
		insert1();
	}
	else if(x==2)
	{
		insert2();
	}
	else{
	printf("Code ses hoyni");
	}
	
}
void insert1(){
	
	watch(head);
	int x,y,cou=0;
	printf("\nEnter after which position you want to add node\t\t");
	scanf("%d",&x);
	printf("Enter the data you want to insert...\t\t");
	scanf("%d",&y);
	node *temp = head;
	node *newnode2 = (node *)malloc(sizeof(node));
	newnode2->data = y;
	while(temp->link!=NULL && cou!=x) //cou is the Index number and it's as previous (Insert after value) program 
	{
		temp = temp->link;
		cou++;
	}
	if(temp->data != x)
	{
		printf("Value dosen't exixt in the list so the node is been added at last\n");
	}
	newnode2->link = temp->link;
	temp->link = newnode2;
}
void insert2(){
	watch(head);
	int x,y,cou=0;
	printf("\nEnter before which you want to add node\t\t");
	scanf("%d",&x);
	printf("Enter the data you want to insert...\t\t");
	scanf("%d",&y);
	node *temp,*prev;
	temp = prev = head;
	node *newnode2 = (node *)malloc(sizeof(node));
	newnode2->data = y;
	while(temp->link!=NULL && cou !=x)//cou is the Index number and it's as previous(Insert before value) program 
	{	
		prev=temp;
		temp = temp->link;
        cou++;
	}
	if(temp==head)
	{
		printf("Value is at the first\n");
		newnode2->link = head;
		head = newnode2;
	}
    else if(cou<x) //Checking if the value given is greater then expected
    {
        newnode2->link = temp->link;
	    temp->link = newnode2;
    }
    else if(x<0)
    {
    	printf("\nIndex dosen't exist\n");
    }
    else{
		newnode2->link = prev->link;
		prev->link= newnode2;
	}
}
int main(){
make(200);
make(590);
make(123);
sel();
watch(head);
return 0;
}
