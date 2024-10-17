#include<stdio.h>

int main() {
    char variable;
    printf("Enter the variable:");
    scanf("%c",&variable);

    if(variable >= '0' && variable <= '9') {
        printf("This variable a digit");

    } else if (variable >= 'a' && variable <= 'z') {
        printf("This variable is lowercase alphabate\n");
        printf("The variable %c convert into uppercase : %c", variable,variable-32);

    } else if (variable >= 'A' && variable <= 'Z') {
        printf("This variable is uppercase alphabate\n");
        printf("The variable %c convert into lowercase: %c", variable,variable+32);

    } else {
        printf("The variable is punctuation symbol\n");
    }
}