#include<stdio.h>
#include<string.h>
int main(){
	char str1[100],str2[100];
	printf("enter the string:");
	scanf("%s",&str1);
	strcpy(str2,str1);
	printf("copy of another is %s",str2);
}
