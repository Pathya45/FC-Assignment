#include <stdio.h>
int main()
{
    int n, count;
    printf("Enter the number:");
    scanf("%d",&n);
    for(int i=1; i<=n;i++)
    {
        if(n%i==0)
        {
            count++;
        }
    }
    if(count==2)
    {
        printf("\n %d Is a prime number",n);
    }
    else{
        printf("\n %d Is not a prime number",n);
    }
    return 0;
}