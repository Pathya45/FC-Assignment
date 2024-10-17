#include <stdio.h>
int main()
{
    int n,x, sum=0,count=0;
    printf("Enter the digit:");
    scanf("%d",&n);
    if(n==0)
    {
        sum= 0;
        count = 1;
    }
    else{
        while(n!=0)
        {
            x= n%10;
            sum= sum+ x;
            count++;
            n=n/10;
        }
    }
    printf("\n sum= %d", sum);
    printf("\n count= %d",count);
}