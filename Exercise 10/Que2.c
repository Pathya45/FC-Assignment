#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
 
int main(int argc, char *argv[]) { 
    if (argc != 2) { 
        printf("Error: Please provide exactly one filename as an argument.\n"); 
        return 1; 
    } 
 
    FILE *file = fopen(argv[1], "r"); 
    if (file == NULL) { 
        printf("Error: Could not open file %s\n", argv[1]); 
        return 1; 
    } 
 
    int lines = 0, words = 0, characters = 0; 
    char ch; 
    int inWord = 0; 
 
    while ((ch = fgetc(file)) != EOF) { 
        characters++; 
        if (ch == '\n') { 
            lines++; 
        } 
        if (isspace(ch)) { 
            if (inWord) { 
                words++; 
                inWord = 0; 
            } 
        } else { 
            inWord = 1; 
        } 
    } 
 
    if (inWord) { 
        words++; 
    } 
 
    fclose(file); 
 
    printf("Lines: %d\n", lines); 
    printf("Words: %d\n", words); 
    printf("Characters: %d\n", characters); 
 
    return 0; 
}