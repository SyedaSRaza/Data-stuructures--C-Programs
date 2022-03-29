#include<stdio.h>

int main()
{
	int data[10], tosearch, flag=0;
	printf("enter your to search value");
	scanf("%d",&tosearch);
	printf("Enter your data");
	for(int i=0;i<10;i++)
	{
		scanf("%d",&data[i]);
	}
	for(int j=0;j<10;j++)
	{
		if(tosearch==data[j])
		{
			printf("Value found at %d",j);
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("value not found");
	}
}
