#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *link;
}*front=NULL,*rear=NULL;


void enqueue()
{
    int value;
    struct node *new_node;
    new_node=malloc(sizeof(struct node));
    printf("Enter the data to be enqueued:");
    scanf("%d",&value);
    new_node->data=value;
    new_node->link=NULL;
    if (front==NULL && rear==NULL)
    {
        front=rear=new_node;
        rear->link=front;
    }
    else
    {
        rear->link=new_node;
        rear=new_node;
        rear->link=front;
        
    }

}


void dequeue()
{
    int value;
    struct node *temp;
    if(front==NULL && rear==NULL)
    {
        printf("\nCircular Queue Underflow\n");
        return;
    }
    else if(front==rear)
    {
        temp=front;
        value=temp->data;
        printf("\nDequeued element is %d\n",value);
        free(temp);
        front=rear=NULL;
        return;
    }
    else
    {
        temp=front;
        value=temp->data;
        printf("\nDequeued element is: %d\n",value);
        front=front->link;
        rear->link=front;
        free(temp);
        return;
    }
}


void display()
{
    int value;
    struct node *ptr;
    if(front==NULL && rear==NULL)
    {
        printf("\nCircular Queue is empty\n");
    }
    else
    {
        ptr=front;
        printf("\n--------CircularQueue Elements--------\n");
        do
        {
            value=ptr->data;
            printf("%d\t",value);
            ptr=ptr->link;
        }while(ptr!=front);
        printf("\n");
        
    }
    
}


void main()
{
    int choice;
    printf("*********CIRCULARQUEUE OPERATIONS***********\n");
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            enqueue();
            printf("Item inserted\n");
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:
            break;
        }
    }
}