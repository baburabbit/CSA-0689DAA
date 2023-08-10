#include<stdio.h>
int main()
{
	int n,m,s,t;
	s=0,t=0;
	printf("enter the no:");
	scanf("%d",&n);
	while(n>0){
		m=n%10;
		s=s+m;
		t=t*10+m;
		n=n/10;
	}
	printf("reversed number is %d",t);
}
