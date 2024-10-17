#include<stdio.h>

void decToBinary(int n){
    if(n > 1){
        decToBinary(n/2);
    }
    printf("%d", n%2);
}

void decimalToOctal(int n){
    if(n > 8){
        decimalToOctal(n/8);
    }
    printf("%d", n%8);
}

void decimalToHexa(int n){
    if(n > 16){
        decimalToHexa(n/16);
    }
    int digit = n%16;
    if(digit < 10)
        printf("%d", digit);
    else
        printf("%c", digit + 'A');
}

void main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    printf("\nDecimal To Binary : ");
    decToBinary(n);

    printf("\nDecimal To Octal : ");
    decimalToOctal(n);
    
    printf("\nDecimal To Hexadecimal : ");
    decimalToHexa(n);
    
    printf("\n");
}