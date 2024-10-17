#include<stdio.h>

int gcdfunc(int a,int b)
{	
	if(b!=0)
	{
		return gcdfunc(a,a%b);
	}
	else 
	{
		return a;
	}
}
int main()
{
	int n1,n2,gcd;
	printf("\nenter the n1");
	scanf("%d",&n1);
	printf("\nenter the n2");
	scanf("%d",&n2);
	gcd=gcdfunc(n1,n2);
	printf("\n GCD of %d and %d is : %d",n1,n2,gcd);
}
	 
