#include<stdio.h>
int main()
{
	int n,remainder,result=0,orinialnumber;
	printf("enter the three number:");
	scanf("%d",&n);
	orinialnumber=n;
	remainder=orinialnumber%10;
	result+=remainder*remainder*remainder;
	orinialnumber=n/10;
	if(orinialnumber=n)
		printf("it is armstrong number");
	else
		printf("it is not armstrong number");
	return 0;	
}
