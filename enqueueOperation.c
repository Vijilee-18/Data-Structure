#include<stdio.h>
#define max_size 5
int main(){
    int queue[max_size],item;
    int front,rear=-1;
    for(int i=0;i<=max_size;i++)
    {
        if(rear==max_size-1){
            printf("Cannot add any more...OVERFLOW");
        }
        else{
            rear=rear+1;
            printf("Enter the element to be added:");
            scanf("%d",&item);
            queue[rear]=item;
            
        }
    }
    printf("\nThe Queue Elements are:\n");
    for(int i=0;i<max_size;i++){
        printf("%d\t",queue[i]);
    }
    return 0;
}