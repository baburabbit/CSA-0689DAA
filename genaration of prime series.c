#include <stdio.h>
#include<math.h>
int main()
{
    int n,i,j,c=0;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("The prime numbers in between the range 1 to %d:",n);
    for(i=2;i<=n;i++) {
        for(j =2;j<=sqrt(i);j++) {
            if(i%j==0){
                c=1;
                break;
            }
        }
        if(c==0)
            printf("%d ",i);
        c=0;
    }
    return 0;
}
