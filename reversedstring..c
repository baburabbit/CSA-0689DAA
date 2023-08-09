#include<stdio.h>
int main()
{
	char str1[100];
	int n,i;
	printf("enter the string:");
	scanf("%s",str1);
	n=strlen(str1);
	for(i=n-1;i>=0;i--){
		printf("%c",str1[i]);
	}
	return 0;
}
