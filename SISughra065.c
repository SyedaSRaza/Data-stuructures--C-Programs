#include<stdio.h>
#include<stdlib.h>
  
// structure 
struct Node
{
    int data;
    struct Node *next;
};

struct Node *start = NULL;

// Function to insert
void insert();
  
// Function to bubble sort 
void bubbleSort(struct Node *start);
  
//Function to swap data
void swap(struct Node *a, struct Node *b);
  
// Function to print nodes
void printList(struct Node *start);
  
int main()
{
    int sizeofarr,arr[sizeofarr];
    int listsize, i;
	
	printf("Enter size of array:");
	scanf("%d",&sizeofarr);

  	for (i = 0; i< sizeofarr; i++)
        insert();
  
    // print
    printf("\n Linked list before sorting \n");
    printList(start);
  
    // sort the linked list
    bubbleSort(start);
  
    // print list after sorting 
    printf("\n Linked list after sorting \n");
    printList(start);
  
    return 0;
}
  
  
// Function to insert a node
void insert()
{
	
	struct Node* temp;                                  
	temp = (struct Node*)malloc(sizeof(struct Node));
    //data input
    printf ("enter data value: ");                      
    scanf ("%d", &temp->data);
    temp->next=NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        struct Node* curr = start; 
        while(curr->next!=NULL)
        {
            curr = curr->next;
        }
        curr->next=temp;
    }

}
  
//print nodes
void printList(struct Node *start)
{
    if(start==NULL)
    {
        printf("list empty");
    }
    else
    {
        int a = 0;
        struct Node* curr = start; 
        do
        {
            printf("%d", curr->data);
            printf(" ");
            curr = curr->next;
            a = a + 1;

        }
        while(curr!=NULL);

    }
}
  
// Bubble sort
void bubbleSort(struct Node *start)
{
    int flag, i;
    struct Node *temp;
    struct Node *curr = NULL;
  //bubble sort code
    if (start == NULL)
        return;
  
    do
    {
        flag = 0;
        temp = start;
  
        while (temp->next != curr)
        {
            if (temp->data > temp->next->data)
            { 
                swap(temp, temp->next);
                flag = 1;
            }
            temp = temp->next;
        }
        curr = temp;
    }
    while (flag);
}
  
//function for swapping as in bubble sort function it was giving run time error
void swap(struct Node *a, struct Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
