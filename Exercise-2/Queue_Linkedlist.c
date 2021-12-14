#include<stdio.h>
#include<stdlib.h>



struct node
{
    int data;
    struct node *link;
}   *front=NULL,*rear=NULL;



void enqueue()
{
    int value;
    struct node *new_node;
    new_node=malloc(sizeof(struct node));
    printf("Enter the data to be enqueued: ");
    scanf("%d",&value);
    new_node->data=value;
    new_node->link=NULL;
    if(front==NULL && rear==NULL)
    {
        front=rear=new_node;
    }
    else
    {
            rear->link=new_node;
            rear=new_node;
    }

}


void dequeue()
{
    int value;
    struct node *temp;
    if (front==NULL)
    {
        printf("\nQueue underflow\n");
    }
    else
    {
        value=front->data;
        temp=front;
        front=front->link;
        printf("\nDequeued element is: %d\n",value); 
        free(temp);
    }
    
}



void display()
{
    int value;
    struct node *ptr;
    if(front==NULL)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        ptr=front;
        printf("---------Queue Elements------\n");
        while(ptr!=NULL)
        {
            value=ptr->data;
            printf("%d\t",value);
            ptr=ptr->link;
        }
        printf("\n");
    }
}



void main()
{
    int choice;
    printf("***********QUEUE OPERATIONS***********");
    while(1)
    {
        
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            enqueue();
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
