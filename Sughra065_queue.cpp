#include<stdio.h>
#include<conio.h>

int queue[5], size=5,front=0,rear=0;


int enqueue ()
{
	int j=1;
	
    if(rear==size)
        printf("\n Queue is Full");
    else
	{
		printf("\nEnter no %d:",j++);
    	scanf("%d",&queue[rear++]);
	}
}
int dequeue()
{
	if(front==rear)
        printf("\nQueue is empty");
    
	else
    {
     printf("\nDeleted value is %d",queue[front++]);
      size++;
    }
}

void printqueue()
{
	printf("\nYour Queue is:\n");
    if(front==rear)
       printf("\nQueue is Empty");
    else
    {
        for(int i=front; i<rear; i++)
           {
            printf("%d",queue[i]);
            printf("\n");
           }
		printf("\n");
	}
}

int main()
{	
	int opt;
	while(1)
	{
		printf("Enter 1 for enqueue, 2 for dequeue, 3 to exit the program:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				enqueue ();	
				printqueue();
				break;
			case 2:
				dequeue();
				printqueue();
				break;
			default:
				printf("Exit the program:");
				return 0;
		}
	}
}
