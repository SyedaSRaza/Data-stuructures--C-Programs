#include<stdio.h>
#include<conio.h>
int binarySearch(int arr[], int l, int r, int tosearch)
{
	int mp;
   if (r >= l)
   {
        mp = l + (r - l)/2;
  	//value at midpoint(mp)
        if (arr[mp] == tosearch)  return mp;
  
        // R=mp-1
        if (arr[mp] > tosearch) return binarySearch(arr, l, mp-1, tosearch);
  
        // Else-(L=mp+1)
        return binarySearch(arr, mp+1, r, tosearch);
   }
  
   // We reach here when element is not present in array
   return -1;
}
int main(void)
{
	int arr[10],tosearch,i;
	printf("Enter your array:");
	
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	
   printf("The target value:");
   scanf("%d",&tosearch);
   
   int n = sizeof(arr)/ sizeof(arr[0]);

   int index = binarySearch(arr, 0, n-1, tosearch);
   
   if(index == -1)
	{
   		printf("Value not found");
   }
   	else{
        printf("Value found at: %d index", index);
	}		
   return 0;
}
