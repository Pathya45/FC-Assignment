#include <stdio.h>
int main()
{
    int n,digit,original,reverse;
    printf("Enter the number");
    scanf("%d",&n);
    original = n;
    
        while(n!=0)
        {
            digit= n%10;
            reverse = reverse*10+digit;
            n=n/10;

        }
        if(original== reverse)
        {
            printf("\n %d Is a palindrome",original);
        }
        else{
            printf("\n %d Is not a palindrome",original);
        }
    
    return 0;
   
}