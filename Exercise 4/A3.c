#include<stdio.h>

int fact(num)
{
	if(num==0 || num==1)
	{
		return 1;
	}
	else
	{
		return(num * fact(num-1));
	}
}

int main()
{
	int num,result;
	printf("\nenter the number ");
	scanf("%d",&num);
	result=fact(num);
	printf("factorial of %d is %d\n",num,result);
	return 0;
}
