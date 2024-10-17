#include <stdio.h> 
#include <string.h> 
 

void copyString(char *source, char *destination) { 
    while (*source != '\0') { 
        *destination = *source; 
        source++; 
        destination++; 
    } 
    *destination = '\0'; 
    printf("String copied successfully: %s\n", destination); 
} 
 

void concatenateStrings(char *str1, char *str2) { 
    
    while (*str1 != '\0') { 
        str1++; 
    } 
 

    while (*str2 != '\0') { 
        *str1 = *str2; 
        str1++; 
        str2++; 
    } 
    *str1 = '\0'; 
    printf("Strings concatenated successfully: %s\n", str1); 
} 
 

int countOccurrences(char *str, char ch) { 
    int count = 0; 
    while (*str != '\0') { 
        if (*str == ch) { 
            count++; 
        } 
        str++; 
    } 
    return count; 
} 
 

void replaceCharacter(char *str, char oldChar, char newChar) { 
    while (*str != '\0') { 
        if (*str == oldChar) { 
            *str = newChar; 
        } 
        str++; 
    } 
    printf("Character replaced successfully: %s\n", str); 
} 
 
int main() { 
    int choice; 
    char str1[100], str2[100], ch, newCh; 
 
    do { 
        printf("\nMenu:\n"); 
        printf("1. Copy one string to another\n"); 
        printf("2. Concatenate two strings\n"); 
        printf("3. Count occurrences of a character in a string\n"); 
        printf("4. Replace all occurrences of a character by another\n"); 
        printf("5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
         
                printf("Enter the source string: "); 
                scanf("%s", str1); 
                copyString(str1, str2); 
                printf("Copied string: %s\n", str2); 
                break; 
 
            case 2: 
            
                printf("Enter the first string: "); 
                scanf("%s", str1); 
                printf("Enter the second string: "); 
                scanf("%s", str2); 
                concatenateStrings(str1, str2); 
                printf("Concatenated string: %s\n", str1); 
                break; 
 
            case 3: 
              
                printf("Enter the string: "); 
                scanf("%s", str1); 
                printf("Enter the character to count: "); 
                scanf(" %c", &ch); 
                int count = countOccurrences(str1, ch); 
                printf("Character '%c' occurred %d times.\n", ch, count); 
                break; 
 
            case 4: 
                
                printf("Enter the string: "); 
                scanf("%s", str1); 
                printf("Enter the character to be replaced: "); 
                scanf(" %c", &ch); 
                printf("Enter the new character: "); 
                scanf(" %c", &newCh); 
                replaceCharacter(str1, ch, newCh); 
                printf("Modified string: %s\n", str1); 
                break; 
 
            case 5: 
                printf("Exiting...\n"); 
                break; 
 
            default: 
                printf("Invalid choice! Please try again.\n"); 
        } 
    } while (choice != 5); 
 
    return 0; 
} 
