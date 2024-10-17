#include<stdio.h>
int reversenum(int n)
{
	if(n==0)
	{
		return 0;
	}
	printf("%d",n%10);
	n=n/10;
	if(n!=0)
	{
	reversenum(n);
	}
}	

void main()
{
	int n;
	printf("\nenter number to reverse ");
	scanf("%d",&n);
	reversenum(n);
}