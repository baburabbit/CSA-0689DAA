#include<stdio.h>
#include<string.h>
int main()
{
	int length,i,b=0;
	char s[100];
	printf("enter the value:");
	scanf("%s",s);
	length=strlen(s);
	for(i=0;i<length;i++)
	{
		if(s[i]==s[length-i-1])
		b++;
	}
	if(b==i)
	printf("palindrome");
	else
	printf("not palindrome");
		
}
