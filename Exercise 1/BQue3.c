#include<stdio.h>

int main() {
    float C, Java, Python;

    printf("Enter the marks:");
    scanf("%f%f%f",&C,&Java,&Python);

    float avg=(C+Java+Python)/3;
    printf("The average marks: %f",avg);

    if (avg>=80 && avg<=100) {
        printf("\nStudent is in Distinction");
    } else if (avg>=70) {
        printf("Student is in Class 1");
    } else if (avg>=60) {
        printf("Student is in Class 2");
    } else {
        printf("Student is fail");
    }
}