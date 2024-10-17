#include<stdio.h>

int main() {
    char variable;
    printf("Enter the variable:");
    scanf("%c",&variable);

     if (variable >= 48 && variable <= 58) {
        printf("This variable a digit");

    } else if (variable >= 97 && variable <= 122) {
        printf("This variable is lowercase alphabate\n");

    } else if (variable >= 65 && variable <= 90) {
        printf("This variable is uppercase alphabate\n");
    }
}