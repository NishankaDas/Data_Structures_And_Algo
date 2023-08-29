#include<stdio.h>
#include<stdlib.h>
int main()
{
    int* arr;
    arr = (int*)malloc(10*sizeof(int));
    int top =0;  
    while(1)
    {
        int u;
        printf("Enter 1 to insert 2 to delete 3 to see and other to exit\t");
        scanf("%d",&u);
        if(u==1){
            int x;
            if(top<10){
                printf("Enter data...\t");
                scanf("%d",&x);
                arr[top]=x;
                top++;
            }
            else{
                printf("Overflow");
            }
             
        }
        else if(u==2){
            
                        if(top>=0)
                        {
                            arr[top]=0;
                            top--;
                        }
                        else{
                            printf("Stack Under Flow");
                        }
                    
        }  
        else if(u==3)
        {
            
                 printf("%d\n",arr[--top]);
                

           }
        else{
            printf("Hodol Kut Kut");
            break;
            }
    }
}