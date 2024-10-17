#include <stdio.h> 
#include <string.h> 
 
int main(int argc, char *argv[]) { 
   
    if (argc != 4) { 
        printf("Usage: %s <string> <char_to_replace> <replacement_char>\n", argv[0]); 
        return 1; 
    } 
 
    char *str = argv[1]; 
    char char_to_replace = argv[2][0]; 
    char replacement_char = argv[3][0]; 
 
   
    for (int i = 0; i < strlen(str); i++) { 
        if (str[i] == char_to_replace) { 
            str[i] = replacement_char; 
        } 
    } 
 
   
    printf("Modified string: %s\n", str); 
 
    return 0; 
}