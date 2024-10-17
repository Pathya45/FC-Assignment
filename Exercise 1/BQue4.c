#include<stdio.h>

int main(){

    int ch ;
    float l,s ,b ;
    float base,h ;
 

    printf("enter the menu \n 1.area of square \n 2.area of rectangle \n 3.area of triangle");
    scanf("%d",&ch);

    switch(ch){

    case 1 : 

    printf("enter the length");
    scanf("%f",&s);
    printf("The area of square is %f " , s*s);
    break ;
    

    case 2 :

    printf("enter the length");
    scanf("%f",&l);

    printf("enter the breadth");
    scanf("%f",&b);

    printf("The area of rectangle is %f " , l*b);
    break;

    case 3 :

    printf("enter the height");
    scanf("%f",&h);

    printf("enter the base");
    scanf("%f",&base);

    printf("The area of rectangle is %f " , 1/2*(base*h));

    break;

    default : printf("invalid");

    }

}