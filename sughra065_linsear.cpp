#include <stdio.h>
void linsearch(int *data, int tosearch){
	int flag=0;
		for(int i=0;i<10;i++){
		if(tosearch==data[i])
		{
			printf("value found at %d",i);
			flag=1;
			break;
		}
	}
	if(flag==0){
		printf("value not found");
	}
}

int main(){
	
	int flag=0,i,tosearch,data[10];
	
	printf("Enter your array");
	for(i=0;i<10;i++){
		scanf("%d",&data[i]);
	}
	
	printf("Enter the value you want to search");
	scanf("%d",&tosearch);
	
	linsearch(data,tosearch);

return 0;
}
