#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5

int STACK[MAXSIZE],n,i,ch,TOP=-1,elem;
void disp()
{
	for(i=0;i<=TOP;i++)
		printf("%d ",STACK[i]);

}
void push()
{
	
	printf("\nEnter the Element you want to insert: ");
	scanf("%d",&elem);
	TOP=TOP+1;
	STACK[TOP]=elem;
    disp();
}



void pop()
{
	elem=STACK[TOP];
	printf("\nDeleted Element is: %d\n",elem );
	TOP=TOP-1;
	disp();
}




void main()
{
		do{
		printf("\n\nSELECT YOUR STACK OPERAION\n\n1.Insertion\n2.Deletion\n3.Display\n4.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:if(TOP!=MAXSIZE)
				    {
				    	push();
				    }
				    else
				    {
				    	printf("\nStack Overflow\n");
				    }
				    break;				
			case 2:if(TOP!=-1)
					{
						pop();
					}
					else
					{
						printf("\nStack is Empty\n");
					}
					break;

			case 3:if(TOP!=-1)
					{
						printf("\nSTACK = ");
						disp();
					}
					else
					{
						printf("\nStack is Empty\n");
					}
					break;
			case 4:exit(0);
			default :printf("Invalid choice");

		}
	}while(1);
}

