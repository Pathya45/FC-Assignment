#include<stdio.h>

int main() {
  int n;
  char a='A';

  printf("Enter the no of rows:");
  scanf("%d",&n);

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n-i; j++) {
      printf(" %2c ",a++);
      printf(" ");
    }
    printf("\n");
  }
}