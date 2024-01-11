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
void print(int num){
	int i;
	printf("\nThe Array is displayed...\n");
	for(i =0; i<num; i++)
	{
		printf("%d \t",arr[i]);
	}	
}
void sort(int num){
	int i,j,key;
	printf("\n\nSorting started...\n\n");
	for(i = 1; i<num; i++)
	{
		key = arr[i];
		j = i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			 j= j-1;
		}
		arr[j+1] = key;
	}
	print(num);
}
int main(){
	input();
return 0;
}
