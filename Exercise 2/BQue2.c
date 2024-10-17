#include<stdio.h>

int factorial (int num)
{
    int fact = 1;
    for(int i=1; i<=num; i++)
    {
        fact*=i;
    }
    return fact;
}

int pow1(int x, int n) 
{
    int pow=1;
    for(int i=1; i<=n; i++)
    {
        pow=pow*x;
    }
    return pow;
}

int main() {
    int n, x;
    float sum=0.0;
    printf("Enter the real number:");
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        sum= sum+((float)factorial(i)/(float)pow1(x,i));
    }
    printf("%f",sum);
    return 0;
}