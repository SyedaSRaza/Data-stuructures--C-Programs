#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
	{
		int data;
		struct Node *next;
	}*start=NULL;
	
//insert function
int insert()
{
	struct Node*temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	//input data
	printf("Enter Data value:\n");
	scanf("%d",&temp->data);
	
	temp->data;
	temp->next=NULL;
	
	if(start==NULL)
	{
		start=temp;	
	}
	else
	{
		struct Node*curr=start;
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}	
		curr->next=temp;
	}
}
//printing output
int printallNodes(int num)
{
    if (start==NULL)
    {
        printf("The list is empty");
    }
    else
    {
        int a=0;
        struct Node *curr=start;
        while (a!=num)
        {
            printf("%d ",curr->data);
            curr=curr->next;
            a+=1;
        }
    }   
}
int sorting(int num)
{
	
	
}

//main function
int main()
{
	int num,i,tosearch;
	printf("Enter number of times you want to run the loop");
	scanf("%d",&num);
	
	for(i=0;i<num;i++)
	{
		insert();
	}
	printallNodes(num);
	sorting(num);
	printallNodes(num);
}
