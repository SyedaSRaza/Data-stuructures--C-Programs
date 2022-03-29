#include<stdio.h>
#include<conio.h>

int main(){
	int num,arr[10],i;
	
	printf("Enter the number you want to add with each value to array:");
	scanf("%d",&num);
	
	printf("Enter your array values:");
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("After adding the number to your array, the result will be:");
	
	for(i=0;i<10;i++)
	{
		arr[i]=arr[i]+ num;
		printf("%d \n",arr[i]);	
	}	
	return 0;
}
