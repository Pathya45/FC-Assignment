#include <stdio.h> 
#include <stdlib.h> 
 
int main(int argc, char *argv[]) { 
 
    if (argc != 4) { 
        printf("Error: Invalid number of arguments. Please enter exactly 3 integers.\n"); 
        return 1;   
    } 
 
  
    int num1 = atoi(argv[1]); 
    int num2 = atoi(argv[2]); 
    int num3 = atoi(argv[3]); 
 
  
    int min = (num1 < num2) ? ((num1 < num3) ? num1 : num3) : ((num2 < num3) ? num2 : num3); 
 
   
    int max = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3); 
 
   
    float avg = (num1 + num2 + num3) / 3.0; 
 
   
    printf("Minimum: %d\n", min); 
    printf("Maximum: %d\n", max); 
    printf("Average: %.2f\n", avg); 
 
    return 0; 
}