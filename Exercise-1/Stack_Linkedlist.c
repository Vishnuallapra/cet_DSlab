#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
}
*Top=NULL;


void push()
{
    int value;
    struct node *new_node;
    new_node=malloc(sizeof(struct node));
    printf("Enter the data to be pushed:");
    scanf("%d",&value);
    new_node->data=value;
    new_node->link=NULL;
    if(Top==NULL)
    {
        Top=new_node;
        
    }
    else
    {
        new_node->link=Top;
        Top=new_node;
        
    }
}


void pop()
{
    int value;
    struct node *temp;
    if (Top==NULL)
    {
        printf("\nStack underflow\n");
        
    }
    else
    {
        value=Top->data;
        temp=Top;
        Top=Top->link;
        printf("\nDeleted element is: %d\n",value);
        free(temp);
    }
}


void display()
{
    int value;
    struct node *ptr;
    if(Top==NULL)
    {
        printf("\nStack is empty\n");
        
    }
    else
    {
        ptr=Top;
        printf("\n-----Stack Elements ----\n");
        while(ptr!=NULL)
        {
            value=ptr->data;
            printf("%d\n",value);
            ptr=ptr->link;
            
        }
    printf("\n");
    }
}

void main()
{
    int choice;
    printf("****************STACK OPERATIONS*****************");
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
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
