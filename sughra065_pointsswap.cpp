#include<stdio.h>
void swap(int *a, int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
int main(){
	int x=55, y=88;
	swap(&x,&y);
	printf("x is %d and y is %d",x,y);
}
