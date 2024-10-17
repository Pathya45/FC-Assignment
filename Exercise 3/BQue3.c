#include<stdio.h>
int power(int x, int y)
{
    int result =1; 
    for(int i = 1; i<=y;i++)
    {
        result = result *x;
    }
    return result;
}
int factorial(int num)
{
    int result = 1;
    for(int j=1; j<= num; j++)
    {
        result = result*j;
    }
    return result;
}
int main()
{
    int n;
    float x, sum =0;
     printf("enter value of x \n");
     scanf("%f",&n);
     printf("enter value of n \n");
     scanf("%d",&n);
     for(int i =0; i<n ; i++)
     {
        int sign=(i%2 == 0)? 1: -1;
        sum = sum +sign *(power(x,2*i+1)/ factorial(2*i+1));
     }
     printf("sum of first %d terms of taylors series sin(%.2f) = %.2f\n", n, x,sum);
}