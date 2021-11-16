#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5

int QUEUE[MAXSIZE],n,i,ch,REAR=-1,FRONT=-1,data;
void disp()
{
	for(i=FRONT;i<=REAR;i++)
		printf("%d ",QUEUE[i]);

}
void enque()
{
	if(FRONT==-1)
	{
		printf("\nEnter the Element you want to insert: ");
		scanf("%d",&data);
		REAR=FRONT=0;
		QUEUE[REAR]=data;
		disp();
	}
	else
	{
		printf("\nEnter the Element you want to insert: ");
		scanf("%d",&data);
		REAR=REAR+1;
		QUEUE[REAR]=data;
	    disp();
	}
}



void dequeue()
{
	data=QUEUE[FRONT];
	printf("\nDeleted Element is: %d\n",data );
	FRONT=FRONT+1;
	disp();
}




void main()
{
		do{
		printf("\n\nSELECT YOUR QUEUE OPERAION\n\n1.Insertion\n2.Deletion\n3.Display\n4.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:if(REAR!=MAXSIZE)
				    {
				    	enque();
				    }
				    else
				    {
				    	printf("\nQueue Overflow\n");
				    }
				    break;				
			case 2:if(FRONT==-1 || FRONT>REAR)
					{
						printf("\nQueue is Empty\n");
					}
					else
					{
						dequeue();
					}
					break;

			case 3:if(REAR!=-1)
					{
						printf("\nQUEUE = ");
						disp();
					}
					else
					{
						printf("\nQUEUE is Empty\n");
					}
					break;
			case 4:exit(0);
			default :printf("Invalid choice");

		}
	}while(1);
}

