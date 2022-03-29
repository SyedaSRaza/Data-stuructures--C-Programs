#include<stdio.h>
#include<conio.h>


int main()
{
	
	int num[20],divisor[20],i,tmp,j,a[20],qotient[20],remainder[20];

	printf("Enter data bits\n");
//num inpput
	for(i=0;i<8;i++)
		scanf("%d",&num[i]);

//Divisor input;

	printf("Enter Divisor\n");
	for(i=0;i<4;i++)
		scanf("%d",&divisor[i]);
		
////Because we have to find the remainder, we will add some 0s at the end of the number and the # of 0s will be divisor - 1
////the size of our array is 8, we have taken the limit of 12, because 3 0s will be added


//Division starts:
//Digits of divisor and number are checked, if the digits are equal then 0 is remainder,otherwise 1 is the remainder and loop will run again.
//XOR gate
	for(i=0;i<8;i++)
	{
		tmp=i;
		//remainder is 1, then for loop will run again
		if(num[i]==1)
			{
				for(j=0;j<4;j++)
					{
						//when remainder is 0:
						if(num[tmp]==divisor[j])
						{	
							num[tmp]=0;
							a[j]=0;
						}
						//When remainder is 1:
						else
						{
							num[tmp]=1;
							a[j]=1;	
						}
						tmp=tmp+1;
					}
				qotient[i]=1;
			}
		else
		{
			qotient[i]=0;
		}
	}
	
	printf("\nquotient is: ");
	for(i=0; i<8; i++)	
	printf("%d",qotient[i]);
	//finding quotient
	printf("\nThe remainder is:");
	for(j=0;j<4;j++)
	printf("%d",a[j]);
	
//--------------------------------------------

}

