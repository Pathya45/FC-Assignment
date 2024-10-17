#include<stdio.h>

int iseven(int num);
void main() {
        int num, ans;
        printf("Enter the number:");
        scanf("%d", &num);

        ans= iseven(num);
        if(ans==1) 
        {
                printf("Number is even");
        } else if (ans==0) {
                printf("Number is odd");
        }
}

int iseven(int num1)
{
        if(num1%2==0) {
                return 1;
        } else {
                return 0;
        }
}