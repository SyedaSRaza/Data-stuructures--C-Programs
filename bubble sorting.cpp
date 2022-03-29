#include<stdio.h>
int main() {
  int arr[100], num, i, temp;
  //input num of values
  printf("Enter number of elements in the array:\n");
  scanf("%d", &num); 
  //input array
	printf("Enter %d values\n", num);
  
	for (i = 0; i < num; i++)
	{
    scanf("%d", &arr[i]);
	}

	for (i = 0; i < num; i++) 
	{ 
	// loop n times - 1 per element
        for (int j = 0; j < num - i - 1; j++) 
		{ // last i elements are sorted already
            if (arr[j] > arr[j + 1])
				{  // swop if order is broken
               	temp = arr[j];
              	arr[j] = arr[j + 1];
            	arr[j + 1] = temp;
      			}
    	}
    }
    
  printf("Printing the sorted array:\n");
  for (i = 0; i < num; i++)
     printf("%d\n", arr[i]);
  return 0;
}
