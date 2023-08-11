#include<stdio.h>
int main()
{
	int a[20],i,n,ele,pos;
	printf("enter size");
	scanf("%d",&n);
	printf("enter array");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the position");
	scanf("%d",&pos);
	printf("enter the element");
	scanf("%d",&ele);
	for(i=n-1;i>=pos-1;i--)
		a[i+1]=a[i];
		a[pos-1]=ele;
	printf("after");
	for(i=0;i<=n;i++)
	{
		printf("%d,",a[i]);
}
	}
