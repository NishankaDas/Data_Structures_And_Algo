#include<stdio.h>
int arr[100];
void swap(int a,int b){
	int temp = arr[a];
	arr[a]=arr[b];
	arr[b] = temp;
}
void input(){
	int n,i=0;
	printf("\nEnter Number of Elements in Array : ");
	scanf("%d",&n);
	int x =n;
	while(n>0)
	{
		printf("\nEnter number to be sorted : ");
		scanf("%d",&arr[i]);
		n= n-1;
		i++;
	}
	print(x);
	sort(x);
}
void sort(int num){
	int i,j;
	printf("\n\nSorting started...\n\n");
	for(i = 0; i<num-1; i++)
	{
		for(j=0; j<num-1; j++){
			if(arr[j]>arr[j+1])
			{
				swap(j,j+1);
			}
		}
	}
	print(num);
}
void print(int num){
	int i;
	printf("\nThe Array is displayed...\n");
	for(i =0; i<num; i++)
	{
		printf("%d \t",arr[i]);
	}	
}
int main(){
	input();
return 0;
}
