#include<stdio.h>

int main() {
    int a = 18, b = 45;
    int *p1 = &a, *p2 = &b;

    printf("Before Swapping: a = %d, b = %d\n", a,b);

    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    printf("After Swapping: a = %d, b = %d\n", a,b);

    return 0;
}

// void swap(int *x, int *y) {
//     int temp;

//     temp = *x;
//     *x = *y;
//     *y = temp;
// }

// int main() {
//     int a, b;

//     printf("Enter the value of a and b:");
//     scanf("%d %d",&a,&b);

//     printf("Before Swapping: a = %d, b = %d\n",a,b);

//     swap(&a, &b);

//     printf("After Swapping: a = %d, b = %d\n",a,b);

//     return 0;
// }