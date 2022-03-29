#include<stdlib.h>
#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *start=NULL;

int insert()
{
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data value: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if (start==NULL)
    {
        start=temp;
    }
    else
    {
        struct Node *curr=start;
        while (curr->next!=NULL)
        {
            /* code */
            curr=curr->next;
        }
        curr->next=temp;
    }
}

void searching(int num)
{
    struct Node *curr=start;
    int a=0,flag=0,tosearch;
    printf("\nEnter value to search: ");
    scanf("%d",&tosearch);
    while(a!=num)
    {
        if (tosearch==curr->data)
        {
            printf("Value found at %d\n",&curr->data);
            flag=1;
        }
        curr=curr->next;
        a+=1;
    }
    if (flag==0)
    {
        printf("Value not found\n");
    }

}


void printallnodes(int num)
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

void deletion()
{
    struct Node *curr=start;
    int todelete;
    printf("Enter value to delete: ");
    scanf("%d",&todelete);
    if (start->data==todelete)
    {
        start=start->next;
        free(curr);
    }
    else
    {
        curr=curr->next;
        struct Node *prev=start;
        while (curr!=NULL)
        {
            prev->next=curr->next;
            free(curr);
            break;
        }
        curr=start->next;
        prev=prev->next;
    }
}

int main()
{
    int num,i,j;
    printf("how many nodes:");
    scanf("%d",&num);
    for (i=0;i<num;i++)
    {
        insert();
    }
    printallnodes(num);
    searching(num);
    deletion();
    printallnodes(num);
}