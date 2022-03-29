#include<stdio.h>
#include<conio.h>

int main(){
	int arr[100],mi,i,temp,n;
	
	printf("Enter number of values:");
	scanf("%d",&n);
	
	printf("Enter your array");
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	for(i=0;i<n;i++)
	{
		mi=i;
		for(int j=i+1;j<n;j++)
		{
		if(arr[j]<arr[mi])
		mi=j;
		}
		temp=arr[i];
		arr[i]=arr[mi];
		arr[mi]=temp;
		
} 
	printf("The sorted array is:");
	for(i = 0; i <10; i++)
	printf("%d \n", arr[i]);

	
	return 0;
}
