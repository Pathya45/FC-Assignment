#include<stdio.h>
int power(int,int);
int main()
{
	int pow,num;
	float result;
	printf("\nenter the number");
	scanf("%d",&num);
	printf("\nenter the power");
	scanf("%d",&pow);
	result=power(pow,num);
	printf("%d ^ %d is %d",num,pow,result);
	return 0;
}

int power(int num,int pow)
{	
	if(pow)
	{
	return(num*power(num,pow-1));
	}
	return 1;
}
