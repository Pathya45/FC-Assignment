#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
 
#define CHAR_SET_SIZE 256  
 

void findUnion(char *str1, char *str2) { 
    int hashTable[CHAR_SET_SIZE] = {0}; 
 
    printf("Union: "); 
 
    
    for (int i = 0; str1[i] != '\0'; i++) { 
        if (hashTable[(int)str1[i]] == 0) { 
            printf("%c", str1[i]); 
            hashTable[(int)str1[i]] = 1; 
        } 
    } 
 

    for (int i = 0; str2[i] != '\0'; i++) { 
        if (hashTable[(int)str2[i]] == 0) { 
            printf("%c", str2[i]); 
            hashTable[(int)str2[i]] = 1; 
        } 
    } 
 
    printf("\n"); 
} 
 

void findIntersection(char *str1, char *str2) { 
    int hashTable[CHAR_SET_SIZE] = {0}; 
 
  
    for (int i = 0; str1[i] != '\0'; i++) { 
        hashTable[(int)str1[i]] = 1; 
    } 
 
    printf("Intersection: "); 
 
     
    for (int i = 0; str2[i] != '\0'; i++) { 
        if (hashTable[(int)str2[i]] == 1) { 
            printf("%c", str2[i]); 
            hashTable[(int)str2[i]] = 0; 
        } 
    } 
 
    printf("\n"); 
} 
 
int main(int argc, char *argv[]) { 

    if (argc != 3) { 
        printf("Error: Please provide exactly two string arguments.\n"); 
        return 1; 
    } 
 

    char *str1 = argv[1]; 
    char *str2 = argv[2]; 
 
    
    findUnion(str1, str2); 
    findIntersection(str1, str2); 
 
    return 0; 
}