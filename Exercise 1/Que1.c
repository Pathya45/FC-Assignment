#include<stdio.h>
#include<math.h>

int main() {
    int salary;
    float tax;

    printf("Enter the basic salary:");
    scanf("%d",&salary);

    if(0<salary && salary<=150000) {
        tax=0;
    } else if (150000>=salary && salary<=300000) {
        tax=salary*0.2;
    } else {
        tax=salary*0.3;
    }
    printf("The tax of salary is %f",tax);
}