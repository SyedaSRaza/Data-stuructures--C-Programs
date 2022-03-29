#include<stdlib.h>
#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *start=NULL;

insert()
{
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data value: ");
    scanf("%d",&temp->data);
    if (start==NULL)
    {
        start=temp;
        temp->next=start;
    }
    else //if start is not equal to null
    {
        struct Node *curr=start; //curr=current element
        while (curr->next!=start) 
        {
            /* code */
            curr=curr->next;
        }
        curr->next=temp;
        temp->next=start;
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
        int a=0,b=0;
        struct Node *curr=start;
        while (a!=num)
        {
            printf("%d ",curr->data);
            curr=curr->next;
            a+=1;
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
	int todelete;
	struct Node *curr=start;
	printf("Enter value to delete: ");
	scanf("%d",&todelete);
	if (start->data==todelete)
	{
		start=start->next;
		free(curr);
	}
	else
	{
		curr=start->next;
		struct Node *prev=start;
		while (curr!=NULL)
		{
			if (curr->data==todelete)
			{
				prev->next=curr->next;
				free(curr);
				break;
			}
			curr=curr->next;
			prev=prev->next;
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
