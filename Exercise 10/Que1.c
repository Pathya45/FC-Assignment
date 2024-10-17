#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
 
int main(int argc, char *argv[]) { 
    if (argc != 3) { 
        printf("Error: Please provide exactly two filenames as arguments.\n"); 
        return 1; 
    } 
 
    FILE *sourceFile, *destinationFile; 
    sourceFile = fopen(argv[1], "r"); 
    destinationFile = fopen(argv[2], "w"); 
 
    if (sourceFile == NULL) { 
        printf("Error: Could not open source file %s\n", argv[1]); 
        return 1; 
    } 
 
    if (destinationFile == NULL) { 
        printf("Error: Could not open destination file %s\n", argv[2]); 
        fclose(sourceFile); 
        return 1; 
    } 
 
    char ch; 
    while ((ch = fgetc(sourceFile)) != EOF) { 
        if (isalpha(ch)) { 
            if (islower(ch)) { 
                ch = toupper(ch); 
            } else { 
                ch = tolower(ch); 
            } 
        } 
        fputc(ch, destinationFile); 
    } 
 
    fclose(sourceFile); 
    fclose(destinationFile); 
    printf("Contents copied from %s to %s with case reversed.\n", argv[1], argv[2]); 
 
    return 0; 
}