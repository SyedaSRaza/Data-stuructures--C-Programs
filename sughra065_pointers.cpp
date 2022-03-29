#include<stdio.h>
int main(){
	int a=55,*ptr;
	ptr= &a;
	printf("%d\n",a);
	printf("%u\n",ptr);
	printf("%u\n",&a);
	printf("%u\n",&ptr);
	int x;
	x=*ptr;
	printf("%d\n",x);
	printf("%d\n",*ptr);
	printf("%u\n",*(&a));
	printf("%u",*(&ptr));
}
