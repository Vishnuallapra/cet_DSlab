#include<stdio.h>
#include<stdlib.h>
 int value;
struct node{
int data;
struct node *link;
}*start,*temp,*nwll;

struct node *head = NULL;
void createNodeList(int n)
{

 printf("\nEnter Node 1:");
 scanf("%d",&value);
 start=(struct node *)malloc(sizeof(struct node));
 start->data=value;
 start->link=NULL;
 temp=start;
 for(int i=2;i<=n;i++)
 {
   printf("Enter Node %d:",i);
   scanf("%d",&value);
   nwll=(struct node *)malloc(sizeof(struct node));
   nwll->data=value;
   nwll->link=NULL;
 
   temp->link=nwll;
   temp=temp->link;   
 }
}

void displayList()
{
 
 temp=start;
 while (temp!=NULL){
    printf(" Data = %d\n", temp->data);       
    temp = temp->link;                     
        }
}
void addFirst()
{
      int val;
      struct node *newNode = malloc(sizeof(struct node));
      printf("Enter Value=");
   scanf("%d",&val);
      newNode->data = val;

      newNode->link = start;
      

      start = newNode;
      displayList();
      

}
void addspLoc()
{
      int val,pos;
      struct node *newNode = malloc(sizeof(struct node));
      printf("Enter Value=");
      printf("Enter where you want to insert=");
    scanf("%d",&pos);

   scanf("%d",&val);
      newNode->data = val;

      newNode->link = start;
      

      start = newNode;
      displayList();
      

}
void main()
{
 int n,ch;
 printf("Number of Elements in Linked List : ");
 scanf("%d",&n);
 createNodeList(n);
 printf("\n Data entered in the list : \n");
 displayList();
  while(1)
 {
    printf("-----Menu For Linked List Operations------\n1.Traversal\n2.Insertion at the start\n3.Insertion at a specified location \
\n4.Insertion   at the End\n5.Deletion\n6.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {	
         case 1:  displayList();
                 break;
         case 2: addFirst();break;

       default:printf("hi");
}}

}



















#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int num;                        //Data of the node
    struct node *nextptr;           //Address of the next node
}*stnode;

void createNodeList(int n); // function to create the list
void displayList();         // function to display the list

int main()
{
    int n;
		printf("\n\n Linked List : To create and display Singly Linked List :\n");
		printf("-------------------------------------------------------------\n");
		
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    createNodeList(n);
    printf("\n Data entered in the list : \n");
    displayList();
    return 0;
}
void createNodeList(int n)
{
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));

    if(stnode == NULL) //check whether the fnnode is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
// reads data for the node through keyboard

        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        stnode->num = num;      
        stnode->nextptr = NULL; // links the address field to NULL
        tmp = stnode;
// Creating n nodes and adding to linked list
        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &num);
 
                fnNode->num = num;      // links the num field of fnNode with num
                fnNode->nextptr = NULL; // links the address field of fnNode with NULL
 
                tmp->nextptr = fnNode; // links previous node i.e. tmp to the fnNode
                tmp = tmp->nextptr; 
            }
        }
    }
}
void displayList()
{
    struct node *tmp;
    if(stnode == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        tmp = stnode;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->num);       // prints the data of current node
            tmp = tmp->nextptr;                     // advances the position of current node
        }
    }
} 



 while(1)
 {
    printf("-----Menu For Linked List Operations------\n1.Traversal\n2.Insertion at the start\n3.Insertion at a specified location\n4.Insertion at the End\n5.Deletion\n6.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {	
         case 1:);  displayList()
                 break;
         case 2: if(n<1)
			insertion();
		 else 
			printf("Array Full\n");
                 break;
         case 3:del_Element();
                 break;
         case 4:LL_Search();
                if(ind==-1)
                    printf("Item not found \n");
                 else
                 printf("Searched Element is found at the position Array[] \n");	
                 break;
	 case 5:exit(0);
         default:printf("wrong choice\n");
   }
}












































#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};

struct Node *head = NULL,*temp,*temp2, *new_node;

void insertBeg(int d) {
    struct Node* new_node;
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = d;
    new_node->next = head;
    head = new_node;
}

void insertPos(int d, int pos) {
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = d;
    temp = head;
    if(pos==1) {
        new_node->next = head;
        head = new_node;
        return;
    }
    for(int i=1; i<pos-1; i++) {
            temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void insertEnd(int d) {
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = d;
    temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = new_node;
}
void printList(struct Node* n)
{
    printf("\n");
	while (n != NULL) {
		printf(" %d ", n->data);
		n = n->next;
	}
}

void delete(int d) {
    if(head->data==d) {
    head = head->next;
    return;
    }
    temp = head;
    while(temp->data!=d) {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = temp->next;
} 

void main()
{
	int c,d,pos,n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(int i=0; i<n;i++) {
        printf("Enter the data of node %d: ",i+1);
        scanf("%d",&d);
        if(i==0)
            insertBeg(d);
        else
            insertEnd(d);
    }
    printf("\n1. Create a node at beginning\n2. Create node at position\n3. Create node at end\n4.Delete an element\n5. Display");
    while(1) {
    printf("\nchoice :");
    scanf("%d",&c);
    switch(c) {
            case 1: printf("Enter data of node: ");
                    scanf("%d",&d);
                    insertBeg(d);
                    break;
            case 2: printf("Enter data of node: ");
                    scanf("%d",&d);
                    printf("Enter position of node: ");
                    scanf("%d",&pos);
                    insertPos(d,pos);
                    break;
            case 3: printf("Enter data of node: ");
                    scanf("%d",&d);
                    insertEnd(d);
                    break;     
            case 4: printf("Enter data of node to delete: ");
                    scanf("%d",&d);
                    delete(d);
                    break;
            case 5: printList(head);
                    break;
            
        }
    }
}




