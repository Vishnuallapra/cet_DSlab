#include <stdio.h>
#include<stdlib.h>

//Universal set: {1,2,3,4,5,6,7,8,9} 

int a[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, b[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void create()
{
    int i, n, value;
    printf("Enter the size of first set:");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        a[value - 1] = 1;
    }
    printf("Enter the size of second set:");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        b[value - 1] = 1;
    }
    printf("\n1st Set:\n");
    for (i = 0; i < 9; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    printf("\n2nd Set:\n");
    for (i = 0; i < 9; i++)
    {
        printf("%d", b[i]);
    }
    printf("\n");
}
void output(int s[])
{
    int i;
    printf("\nThe resultant Set is:");
    for (i = 0; i < 9; i++)
    {
        if (s[i] != 0)
            printf("%d", i + 1);
    }
    printf("\n");
}
void setUnion()
{
    int i, s[10];
    for (i = 0; i < 9; i++)
    {
        if (a[i] != b[i])
            s[i] = 1;
        else
            s[i] = a[i];
    }
    for (i = 0; i < 9; i++)
    {
        printf("%d", s[i]);
    }
    output(s);
}
void intersection()
{
    int i, c[10];
    for (i = 0; i < 9; i++)
    {
        if (a[i] == b[i])
            c[i] = a[i];
        else
            c[i] = 0;
    }
    for (i = 0; i < 9; i++)
    {
        printf("%d", c[i]);
    }
    output(c);
}
void setdifference()
{
    int i, c[10];
    for (i = 0; i < 9; i++)
    {
        if (a[i] == 1 && b[i] == 0)
            c[i] = 1;
        else
            c[i] = 0;
    }
    for (i = 0; i < 9; i++)
    {
        printf("%d", c[i]);
    }
    output(c);
}

void main()
{
    int choice;
    printf("-------------SET OPOERATIONS-------");
    while(1){
		printf("\n1.create sets\n2.Union\n3.Intersection\n4.Difference\n5.Exit\nYour choice : ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1: create();
				  break;
			case 2: setUnion();
				  break;
			case 3: intersection();
				  break;
			case 4: setdifference();
				  break;
			case 5: printf("\n Exit from program");
				  exit(0);
		    default: printf("\nEnter a valid choice!");
		}
	}
}