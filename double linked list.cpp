#include<stdlib.h>
#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node*prev;
};
struct Node *start=NULL;

insert()
{
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    
    printf("Enter data value: ");
    scanf("%d",&temp->data);
    
    temp->next=NULL;
    temp->prev=NULL;
    
    if (start==NULL)
    {
        start=temp;
    }
    else //if start is not equal to null
    {
        struct Node *curr=start;
        while (curr->next!=NULL) 
        {
            curr=curr->next;
        }
        curr->next=temp;
        temp->prev=curr;
    }
}

printnodes(int num)
{
    if (start==NULL)
    {
        printf("The list is empty");
    }
    else
    {

        struct Node *curr=start;
        while (curr!=NULL)
        {
            printf("%d ",curr->data);
            curr=curr->next;
  
        }
    }   
}

search(int num,int tosearch)
{
	struct Node *curr=start;
	int a=0,flag=0;
	do
	{
		if (tosearch == curr->data)
		{
			printf("Value found\n");
			flag=1;
		}
		curr = curr->next;
		a+=1;
	}
	while (a!=num);
	if (flag==0)
	{
		printf("Value not found\n");
	}
}

del()
{
	int todelete,a=0;
	struct Node *curr=start;
	printf("Enter value to delete: ");
	scanf("%d",&todelete);
	if (start->data==todelete)
	{
		start=start->next;
		delete(curr);
	}
	else
	{
		curr=start->next;
	//	struct Node *prev=start;
		while (curr!=NULL)
		{
			if (curr->data==todelete)
			{
				curr->prev->next=curr->next;
				delete(curr);
				break;
			}
			curr=curr->next;
			curr->prev=curr->prev->next;
		}
	}
}

int main()
{
    int num,i,j,tosearch;
    printf("number of nodes:");
    scanf("%d",&num);
    for (i=0;i<num;i++)
    {
        insert();
    }
    printnodes(num);
    printf("\nenter value to search: ");
    scanf("%d", &tosearch);
    search(num,tosearch);
    del();
    printnodes(num-1);
}
