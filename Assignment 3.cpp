#include<stdio.h>
#include<conio.h>

int main(){
	int i;
	char arr[20];
	printf("Enter your name:");
	
	for(i=0;i<20;i++)
	{
		arr[i]=getche();
		if(arr[i]==13)
		break;
	}
	printf("Entered string: %s",arr);
	
	for(i=0;i<20;i++)
	{
		if(arr[i]>='a' && arr[i]<='z')
		arr[i]=arr[i]-32;
		
		else if(arr[i]>='A' && arr[i]<='Z')
		arr[i]=arr[i]+32;
	}
	printf("\nChange in case: %s",arr);	
	return 0;

}
