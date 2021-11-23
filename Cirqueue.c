#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 4

int QUEUE[MAXSIZE],n,i,ch,REAR=-1,FRONT=-1,data;
void disp(int A,int B)
{
	for(i=A;i<=B;i++)
		printf("%d ",QUEUE[i]);

}
void enque(int TEMP)
{
	printf("\nEnter the Element you want to insert: ");
	scanf("%d",&data);
	QUEUE[TEMP]=data;
	   
}



void dequeue(int TEMP)
{
	data=QUEUE[TEMP];
	printf("\nDeleted Element is: %d\n",data );
	
}




void main()
{
		do{
		printf("\n\nSELECT YOUR CIRCULAR-QUEUE OPERAION\n\n1.Insertion\n2.Deletion\n3.Display\n4.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:if(FRONT!=(REAR+1)%MAXSIZE)
				    {
				    	if(FRONT==-1 && REAR==-1)
				    	{
				    		REAR=FRONT=0;
				    		enque(REAR);
				    		disp(FRONT,REAR);
				    	}
				    	else if(REAR==MAXSIZE-1 && FRONT!=0)
				    	{
				    		
				    	  	REAR=0;
				    	  	enque(REAR);
				    	  	disp(REAR,FRONT);
				    	}
				    	else
				    	{
				    		
				    		REAR=(REAR+1)%MAXSIZE;
				    		enque(REAR);
				    		disp(FRONT,REAR);
				    	}
				    	
				    	 
				    }
				    else
				    {
				    	printf("\nQueue Overflow\n");
				    }
				    break;				
			case 2:if(FRONT==-1)
					{
						printf("\nQueue is Empty\n");
					}
					else
					{
						if(REAR==FRONT)
						{
							dequeue(FRONT);
							FRONT=REAR=-1;
							disp(FRONT,REAR);
						}
						else
						{
							if(FRONT==MAXSIZE-1)
							{
								dequeue(FRONT);
								FRONT=0;
								disp(FRONT,REAR);
							}
							else
							{
								dequeue(FRONT);
								FRONT=(FRONT+1)%MAXSIZE;
								disp(FRONT,REAR);
							}
						}
					
						
					}
					break;

			case 3:if(REAR!=-1)
					{
						printf("\nQUEUE = ");
						disp(FRONT,REAR);
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

