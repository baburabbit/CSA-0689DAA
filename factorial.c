#include<stdio.h>
int factorial(int n)
{
	int i,fact=1;
	for(i=2;i<=n;i++){
		fact=fact*i;
	}
	return fact;
}
int main()
{
	int n;
	scanf("%d",&n);
	int fact=factorial(n);
	printf("factorial of %d is %d",n,fact);
	return 0;
}
