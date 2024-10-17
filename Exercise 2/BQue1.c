#include<stdio.h>

int main()
{
        int n, a, count=0;
        printf("Enter the number:");
        scanf("%d",&n);

        for(int i=1; i<=n; i++)
        {
                printf("\nEnter %d number:",i);
                scanf("%d",&a);

                for(int j=1; j<=a; j++) {
                        if(a%j==0)
                        {
                                count++;
                        }
                }
                if(count==2) {
                        printf("\n%d Is a prime number",a);
                } else {
                        printf("\n%d Is not a prime number\n",a);
                }
                count=0;
        }
        return 0;
}