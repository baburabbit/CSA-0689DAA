#include<stdio.h>
int main()
{
	int n,i,j,t,arr[10];
	printf("enter the size:");
	scanf("%d",&n);
	printf("the element are:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(arr[j]>arr[j+1]){
				t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}
	}
	printf("bubble sort:");
	for(i=0;i<n;i++){
	printf("%d",arr[i]);
	}
	return 0;
}
