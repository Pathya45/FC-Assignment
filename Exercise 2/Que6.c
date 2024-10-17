#include<stdio.h>

int main() 
{
  int a,b;
  printf("Enter 1st and 2nd number:");
  scanf("%d %d",&a,&b);

  for(int i=a; i<=b; i++) {

    for(int j=1; j<=10; j++) {
      printf("\n %d * %d = %d",i,j,i*j);
      printf("\n");
    }
  }
  return 0;
}