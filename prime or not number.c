#include<stdio.h>
int main()
{
	int n,i,c;
	printf("enter the number:");
	scanf("%d",&n);
	c=0;
	for(i=2;i<n/2;i++){
		if(n%i==0)
		{
			c=1;
			break;
		}
		if(c==0){
			printf("given number is %d  prime",n);	
		}
		else{
			printf("given number is %d not prime",n);
		}
	}
	return 0;
}
