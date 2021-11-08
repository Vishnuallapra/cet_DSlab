#define SIZE 10
#include<stdio.h>

int element,n;
int arr[SIZE],ch,ind;                //int *ptr=arr;   or ptr=&arr[0];

void ptr_Traversal(int *arr,int *n)
{
   for(int i=0;i<*n;i++)
   {
     printf("%d ",*(arr+i));
   }
}

void insertion()
{
int pos,ins_Elemt;
n=n+1;
printf("Enter the Element you want to Insert: ");
scanf("%d",&ins_Elemt);
printf("Enter the position of Element Insertion: ");
scanf("%d",&pos); 
if(pos>=n)
{
  arr[pos]=ins_Elemt;
  pos+=1;
  ptr_Traversal(arr,&pos);

}
else
{
  for(int j=n-1;j>=pos;j--){
      arr[j+1]=arr[j];
  }
  arr[pos]=ins_Elemt;
   pos+=1;
  ptr_Traversal(arr,&pos);
}
}

void del_Element()
{
int del_Elemt;
printf("Enter the Element you want to Delete: ");
scanf("%d",&del_Elemt);
for(int i=0;i<SIZE;i++)
{
       if(del_Elemt==arr[i])
	{
            for(int j=i;j<n;j++)
		arr[j]=arr[j+1];
	
        }
}
  ptr_Traversal(arr,&n);
}

int array_Search()
{
   int i,count=0;
   printf("Enter the Element you want to search: ");
   scanf("%d",&element);
   for( i=0;i<SIZE;i++)
   {
       if(element==arr[i])
	{
          count=i;
        }
   }	  
  if(count>0)
  {
  return count;
  }
  else 
  return -1;
    
  }

void main()
{
 char choice;
 printf("Number of Array Elements : ");
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 {
   scanf("%d",(arr+i));
 }
 do
 {
    printf("-----Menu For Array Operations------\n1.Traversal\n2.Insertion\n3.Deletion\n4.Search\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {	
         case 1:ptr_Traversal(arr,&n);
                 break;
         case 2: if(n<SIZE-1)
			insertion();
		 else 
			printf("Array Full\n");
                 break;
         case 3:del_Element();
                 break;
         case 4:ind=array_Search();
                if(ind==-1)
                    printf("Item not found \n");
                 else
                 printf("Searched Element %d is found at the position Array[%d] \n",element,ind);	
                 break;
         default:printf("wrong choice\n");
   }
   printf("Do you want to continue? (N/Y) : ");
   scanf("%s",&choice);
 }while(choice=='Y' || choice=='y');
}
