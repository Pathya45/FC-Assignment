#include<stdio.h>

int main() {
  int n;
  int a=1;

  printf("Enter the no:");
  scanf("%d",&n);

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=i; j++) {
      printf(" %2d ",a++);
      printf(" ");
    }
    printf("\n");
  }
}