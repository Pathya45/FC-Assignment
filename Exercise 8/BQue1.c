#include <stdio.h> 
#include <stdlib.h> 
 

struct Fraction { 
    int numerator; 
    int denominator; 
}; 
 

void displayAll(struct Fraction* fractions, int n); 
float getFractionValue(struct Fraction f); 
void displayLargestFraction(struct Fraction* fractions, int n); 
void displaySmallestFraction(struct Fraction* fractions, int n); 
void sortFractions(struct Fraction* fractions, int n); 
 
int main() { 
    struct Fraction* fractions; 
    int n, choice; 
 
    printf("Enter the number of fractions: "); 
    scanf("%d", &n); 
 
     
    fractions = (struct Fraction*)malloc(n * sizeof(struct Fraction)); 
 
   
    for (int i = 0; i < n; i++) { 
        printf("Enter details for fraction %d\n", i + 1); 
        printf("Numerator: "); 
        scanf("%d", &fractions[i].numerator); 
        printf("Denominator: "); 
        scanf("%d", &fractions[i].denominator); 
 
      
        if (fractions[i].denominator == 0) { 
            printf("Denominator cannot be zero. Please enter a valid fraction.\n"); 
            i--;  
        } 
    } 
 
   
    do { 
        printf("\nMenu:\n"); 
        printf("1. Display the Largest Fraction\n"); 
        printf("2. Display the Smallest Fraction\n"); 
        printf("3. Sort Fractions\n"); 
        printf("4. Display All Fractions\n"); 
        printf("5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                displayLargestFraction(fractions, n); 
                break; 
            case 2: 
                displaySmallestFraction(fractions, n); 
                break; 
            case 3: 
                sortFractions(fractions, n); 
                printf("Fractions sorted successfully.\n"); 
                break; 
            case 4: 
                displayAll(fractions, n); 
                break; 
            case 5: 
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice! Please try again.\n"); 
        } 
    } while (choice != 5); 
 

    free(fractions); 
 
    return 0; 
} 
 

void displayAll(struct Fraction* fractions, int n) { 
    printf("\nAll Fractions:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("%d/%d\n", fractions[i].numerator, fractions[i].denominator); 
    } 
} 
 

float getFractionValue(struct Fraction f) { 
    return (float)f.numerator / f.denominator; 
} 
 

void displayLargestFraction(struct Fraction* fractions, int n) { 
    int largestIndex = 0; 
    for (int i = 1; i < n; i++) { 
        if (getFractionValue(fractions[i]) > getFractionValue(fractions[largestIndex])) { 
            largestIndex = i; 
        } 
    } 
    printf("\nLargest Fraction: %d/%d\n", fractions[largestIndex].numerator, 
fractions[largestIndex].denominator); 
} 
 

void displaySmallestFraction(struct Fraction* fractions, int n) { 
    int smallestIndex = 0; 
    for (int i = 1; i < n; i++) { 
        if (getFractionValue(fractions[i]) < getFractionValue(fractions[smallestIndex])) { 
            smallestIndex = i; 
        } 
    } 
    printf("\nSmallest Fraction: %d/%d\n", fractions[smallestIndex].numerator, 
fractions[smallestIndex].denominator); 
} 
 

void sortFractions(struct Fraction* fractions, int n) { 
    struct Fraction temp; 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = 0; j < n - i - 1; j++) { 
            if (getFractionValue(fractions[j]) > getFractionValue(fractions[j + 1])) { 
          
                temp = fractions[j]; 
                fractions[j] = fractions[j + 1]; 
                fractions[j + 1] = temp; 
            } 
        } 
    } 
}