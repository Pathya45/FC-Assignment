#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
#define MAX_LINES 100 
#define MAX_LINE_LENGTH 256 
 
void displayFile(const char *filename) { 
    FILE *file = fopen(filename, "r"); 
    if (file == NULL) { 
        perror("Error opening file"); 
        return; 
    } 
 
    char line[MAX_LINE_LENGTH]; 
    int lineNumber = 1; 
 
    while (fgets(line, sizeof(line), file)) { 
        printf("%d: %s", lineNumber++, line); 
    } 
 
    fclose(file); 
} 
 
void displayNthLine(const char *filename, int n) { 
    FILE *file = fopen(filename, "r"); 
    if (file == NULL) { 
        perror("Error opening file"); 
        return; 
    } 
 
    char line[MAX_LINE_LENGTH]; 
    int lineNumber = 1; 
 
    while (fgets(line, sizeof(line), file)) { 
        if (lineNumber == n) { 
            printf("Line %d: %s", n, line); 
            fclose(file); 
            return; 
        } 
        lineNumber++; 
    } 
 
    printf("Error: The file has less than %d lines.\n", n); 
    fclose(file); 
} 
 
void modifyNthLine(const char *filename, int n) { 
    FILE *file = fopen(filename, "r+"); 
    if (file == NULL) { 
        perror("Error opening file"); 
        return; 
    } 
 
    char lines[MAX_LINES][MAX_LINE_LENGTH]; 
    int lineNumber = 0; 
 
    while (fgets(lines[lineNumber], sizeof(lines[lineNumber]), file)) { 
        lineNumber++; 
    } 
 
    if (n > lineNumber) { 
        printf("Error: The file has less than %d lines.\n", n); 
        fclose(file); 
        return; 
    } 
 
    printf("Current line %d: %s", n, lines[n - 1]); 
    printf("Enter new content for line %d: ", n); 
    fgets(lines[n - 1], sizeof(lines[n - 1]), stdin); 
 
    rewind(file); 
    for (int i = 0; i < lineNumber; i++) { 
        fputs(lines[i], file); 
    } 
 
    fclose(file); 
} 
 
void addNLines(const char *filename, int n) { 
    FILE *file = fopen(filename, "a"); 
    if (file == NULL) { 
        perror("Error opening file"); 
        return; 
    } 
 
    for (int i = 0; i < n; i++) { 
        char line[MAX_LINE_LENGTH]; 
        printf("Enter content for line %d: ", i + 1); 
        fgets(line, sizeof(line), stdin); 
        fputs(line, file); 
    } 
 
    fclose(file); 
} 
 
int main() { 
    char filename[100]; 
    printf("Enter the filename: "); 
    scanf("%s", filename); 
    getchar();  
 
    int choice, n; 
 
    while (1) { 
        printf("\nMenu:\n"); 
        printf("1. Display the file\n"); 
        printf("2. Display nth line\n"); 
        printf("3. Modify nth line\n"); 
        printf("4. Add n lines\n"); 
        printf("5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        getchar(); 
 
        switch (choice) { 
            case 1: 
                displayFile(filename); 
                break; 
            case 2: 
                printf("Enter the line number to display: "); 
                scanf("%d", &n); 
                getchar();  
                displayNthLine(filename, n); 
                break; 
            case 3: 
                printf("Enter the line number to modify: "); 
                scanf("%d", &n); 
                getchar();  
                modifyNthLine(filename, n); 
                break; 
            case 4: 
                printf("Enter the number of lines to add: "); 
                scanf("%d", &n); 
                getchar();  
                addNLines(filename, n); 
                break; 
            case 5: 
                printf("Exiting the program.\n"); 
                exit(0); 
            default: 
                printf("Invalid choice. Please try again.\n"); 
        } 
    } 
 
    return 0; 
}