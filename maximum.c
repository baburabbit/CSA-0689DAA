#include<stdio.h>
int main()
{
	int a[20],max,i,n;
	printf("enter the size:");
	scanf("%d",&n);
	printf("elements are:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	max=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		max=a[i];
	}
	printf("%d is largest number",max);
	return 0;
}
