
#include<stdio.h>
void swap(float *a,float *b){
	float t=*a;
	*a=*b;
	*b=t;
}

int main(){
	int i;
	float arr[6];
	printf("Enter your array");
	
	for(i=0;i<6;i++)
		scanf("%f",&arr[i]);
	
	printf("Your array is now");
	for(i=0;i<6;i++)
	{
		swap(&arr[i],&arr[i+1]);
		i=i+1;
	}
	
	for(i=0;i<6;i++)
		printf("%f\n",arr[i]);
		
	return 0;
}
