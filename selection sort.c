#include<stdio.h>
int main()
{
	int arr[10],n,i,j,t;
	printf("enter the size:");
	scanf("%d",&n);
	printf("the elements are:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
		for(i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				if(arr[i]>arr[j]){
					t=arr[i];
					arr[i]=arr[j];
					arr[j]=t;
				}
			}
		}
	printf("selection sort:");
	for(i=0;i<n;i++)
	printf("%d",arr[i]);
	return 0;
}
