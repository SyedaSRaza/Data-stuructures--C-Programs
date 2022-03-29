#include<stdio.h>
#include<conio.h>

int top=0, stack[5],size=5;

void push()
{
	int value;
	printf("Enter value:  ");
	scanf("%d",&value);
	if(top==size)
	{
		printf("stack overflow");
		return;
	}
	else
	{
	
		stack[top]=value;
		top++;
	}
}

int pop()
{
	if(top==0)
	{
		printf("Stack underflow");
	}
	else
	{
		top=top-1;
		printf("The pop value is:%d\n",stack[top-1]);

	}
}

void printstackarray()
{
	int i;
	printf("\nyour stack is:\n");
	for(i=(top-1);i>=0;i--)
	{
		printf("%d\n",stack[i]);
	}
	printf("\n");
}

int main()
{
	int opt;
	while(1)
	{
		printf("Enter 1 for push, 2 for pop, 3 to exit the program:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				push();	
				printstackarray();
				break;
			case 2:
				pop();
				printstackarray();
				break;
			default:
				printf("Exit the program:");
				return 0;
		}
	}
}
