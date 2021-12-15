#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
}   *start=NULL;


void create(int value)
{
    struct node *ptr,*newNode;
    newNode=malloc(sizeof(struct node));
    newNode->data=value;
    newNode->link=NULL;
    ptr=start;
    if (ptr==NULL)
    {
        start=newNode;
        
    }
    else
    {
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=newNode;
        
    }
}



void insert_at_begin(int value)
{
    struct node *newNode;
    newNode=malloc(sizeof(struct node));
    newNode->data=value;
    newNode->link=NULL;
    newNode->link=start;
    start=newNode;
}




void insert_at_middle(int pos,int value)
{
    struct node *ptr,*newNode;
    int count=1;
    newNode=malloc(sizeof(struct node));
    newNode->data=value;
    newNode->link=NULL;
    ptr=start;
    while(count<pos-1)
    {
        ptr=ptr->link;
        count++;
        
    }
    newNode->link=ptr->link;
    ptr->link=newNode;
}





void insert_at_end(int value)
{
    struct node *ptr,*newNode;
    newNode=malloc(sizeof(struct node));
    newNode->data=value;
    newNode->link=NULL;
    ptr=start;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=newNode;
}

void delete_begin()
{
    struct node *temp;
    int value;
    if(start==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    value=start->data;
    printf("Deleted element is :%d\n",value);
    temp=start;
    start=temp->link;
    free(temp);
}

void delete_at_position(int pos)
{
    int value,count=1;
    struct node *ptr,*temp;
    if(start==NULL)
    {
        printf("\nLinked list is empty\n");
        return;
    }
    ptr=start;
    if(pos==1)
    {
        value=temp->data;
        start=temp->link;
        printf("\nDeleted element is %d\n",value);
        free(temp);
        return;
    }
    while(count<pos-1)
    {
        ptr=ptr->link;
        count++;
        if(ptr->link==NULL)
        {
            printf("\nGiven position is not present in the linked list\n");
            return;
        }
    }
    temp=ptr->link;
    value=temp->data;
    ptr->link=temp->link;
    printf("\nDeleted element is %d\n",value);
    free(temp);
    
}
    
    
void delete_at_end()
{
    int value;
    struct node *ptr,*temp;
    if(start==NULL)
    {
        printf("\nLinked list is empty\n");
        return;
    }
    ptr=start;
    while(ptr->link!=NULL)
    {
        temp=ptr;
        ptr=ptr->link;
    }
    temp->link=NULL;
    temp=ptr;
    value=temp->data;
    printf("\nDeleted element is :%d\n",value);
    free(temp);
}


void display()
{
    struct node *ptr;
    ptr=start;
    if (ptr==NULL)
    {
        printf("\nLinked list is empty\n");
        
    }
    else
    {
        printf("\n--------Linked list Elements---------\n");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
    }
}

void main()
{
    int choice,num,value,pos;
    printf("**********LINKEDLIST OPERATIONS***********");
    while(1)
    {
        printf("\n1.Create\n2.Insert at beginning\n3.Insert at a position\n4.Insert at end\n5.Delete at beginning\n6.Delete at a position\n7.Delete at end\n8.Display\n9.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the number of elements to be inserted:");
            scanf("%d",&num);
            for(int i=0;i<num;i++)
            {
                printf("Enter the data:");
                scanf("%d",&value);
                create(value);
            }
            break;
            case 2:
            printf("Enter the data to be inserted:");
            scanf("%d",&value);
            insert_at_begin(value);
            break;
            case 3:
            printf("Enter the position where data to be inserted:");
            scanf("%d",&pos);
            printf("Enter the data to be inserted:");
            scanf("%d",&value);
            insert_at_middle(pos,value);
            break;
            case 4:
            printf("Enter the data to be inserted:");
            scanf("%d",&value); 
            insert_at_end(value);
            break;
            case 5:
            delete_begin();
            break;
            case 6:
            printf("Enter the position where element to be deleted:");
            scanf("%d",&pos);
            delete_at_position(pos);
            break;
            case 7:
            delete_at_end();
            break;
            case 8:
            display();
            break;
            case 9:
            exit(0);
            default:
            break;
        }
    }
}
