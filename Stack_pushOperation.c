#include<stdio.h>
int main(){
    int size,Top;
    printf("Enter the Size of Stack:");
    scanf("%d",&size);
    int stack[size];
    printf("Enter the Stack elements:\n");
    for(int i=0;i<size-1;i++){
        scanf("%d",&stack[i]);
        Top=i;
    }
    int choice;
    printf("Click 1 to add an element:");
    scanf("%d",&choice);
    if(choice==1){
        if(Top==size-1){
            printf("ERROR...Stack is full");
        }
        else{
            int item;
            Top=Top+1;
            printf("Enter the Element to be added:");
            scanf("%d",&item);
            stack[Top]=item;
            
        }
    }else{
        printf("Thanks...");
    }
    printf("Stack After adding new Element:\n");
    for(int i=0;i<size;i++){
        printf("%d\t",stack[i]);
    }
    return 0;
    
}