#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max];
int front=-1,rear=-1;
void enqueue(int value)
{ 
  if((front==0&&rear==max-1)||(rear+1)%max==front)
  {
    printf("Queue is full");
    return ;
  }
  if(front==-1)
  {
    front=rear=0;
   } 
   else{
   rear=(rear+1)%max;
   }
   queue[rear]=value;
  }
void dequeue()
{
  if(front==-1) 
  {
    printf("Queue is empty ");
    return ;
  }
  printf("Deleted :%d",queue[front]);
  if(front==rear)
  {
    front=rear=-1;
  }
  else
  {
    front=(front+1)%max;}
   }
   void display()
   {
   if(front==-1){
   printf("Queue is empty ");
   return ;}
   printf("Queue :");
   int i=front;
   while(1){
   printf("%d",queue[i]);
   if(i==rear)
   {
   break;}
   i=(i+1)%max;
   }printf("\n");}
   int main(){
   int choice,value;
   while(1)
   {
     printf("\n ---Circular Queue---\n");
     printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
     printf("\nEnter your choice:");
     scanf("%d",&choice);
     switch(choice){
     case 1:
          printf("Enter the value:");
          scanf("%d",&value);
          enqueue(value);
          break;
    case 2:
          dequeue();
          break;
    case 3:
          display();
          break;
    case 4:
          exit(0);
          break;
    default:
          printf("Invalid Choice");
          }
         }
         return 0;
         }


