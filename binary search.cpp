#include<stdio.h>

int main()
{
	int data[10], tosearch, mp, flag=0;
	printf("enter your to search value");
	scanf("%d",&tosearch);
	printf("Enter your data");
	for(int i=0;i<10;i++)
	{
		scanf("%d",&data[i]);
	}
	int l=0, r=9;
	while(l<=r)
	{
		mp=(l+r)/2;
		
		if(tosearch==data[mp])
		{
			printf("Value found at %d",mp);
			flag=1;
			break;
		}
		else if(tosearch<data[mp])
		{
			r=mp-1;
		}
		else{
			l=mp+1;
		}
	}
	if (flag==0)
	{
		printf("not found");
	}
	
}
