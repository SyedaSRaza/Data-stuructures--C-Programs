#include<stdio.h>

int main(){
	int flag=0,i,tosearch,data[10],midpoint,L=0,R=9;
	
	printf("Enter your array");
	for(i=0;i<10;i++){
		scanf("%d",&data[i]);
	}
	
	printf("Enter the value you want to search");
	scanf("%d",&tosearch);
	
	while(L<=R){
		midpoint=(L+R)/2;
		
		if(tosearch==data[midpoint])
		{
			printf("Value found at %d",midpoint);
			flag=1;
			break;	
		}
		else if(tosearch<data[midpoint])
		{
			R=midpoint-1;
		}
		else
		{
			L=midpoint+1;
		}
	}	
	if(flag==0)
	{
		printf("value not found");
	}
return 0;
}
