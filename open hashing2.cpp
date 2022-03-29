#include <stdio.h>
#include <stdlib.h>

struct node
{
	float data;
    struct node *next;
};
struct node arr[10];
int size =10;

void insert()
{
	int index, ientered;
	float entered;
	printf("Enter value : ");
    scanf("%f", &entered);
    ientered=entered;
    index = ientered%10;

	if (arr[index].data ==-1)
	{
		arr[index].data = entered;
	}
	else
	{
		struct node *temp;
	    temp = (struct node *)malloc(sizeof(struct node));
	    temp->data = entered;
		temp->next = NULL;
	    if (arr[index].next == NULL)
	        arr[index].next = temp;
		else
	    {
	        struct node *curr = arr[index].next;
	        while(curr ->next != NULL)
	        {
	        	curr= curr->next;
			}
	        curr->next = temp;
	    }
	    
	}	
}
void Search()
{
	
	int index, i_search;
	float tosearch;
	
	printf("enter Value To Search :");
	scanf("%f", &tosearch);
	i_search = tosearch;
	index = i_search% size;
	
	if(tosearch==arr[index].data)
		printf("Value  %f found at %d", tosearch,index);
	else
	{
		struct node *curr  = arr[index].next;
		while(curr != NULL)
		{
			if( curr->data == tosearch)
				{
					printf("Value  %f found", tosearch);
					break;
				}
			curr=curr->next;
			}
		
		}	
} 

int main() {
  int key, i;
  
	for( i = 0; i<10 ; i++)
	{
		arr[i].data = -1;
		arr[i].next = NULL;
	} 

    while (1)
    {
        printf("\n\nOPTIONS : \n 1. Insert Data\n 2. Search Data\n 3. Exit\n\n\n  ENTER KEY : ");
        scanf("%d", &key);

        switch (key)
        {
            case 1:
         	{         	
                insert();
                break;
            }
            case 2:
            {
                Search();
                break;
            }
            case 3:
            {
                exit(0);
                break;
            
        	}
    	}
	}
}
