#include<stdio.h>
int main()
{
	int n,m,s;
	s=0;
	printf("enter the no:");
	scanf("%d",&n);
	while(n>0){
		m=n%10;
		s=s+m;
		n=n/10;
	}
	printf("sum of digit is %d",s);
	return 0;
}
